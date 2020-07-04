#include "ir_sensor_runtime.hpp"

// Keeping the latest distance measurements for our IR sensors. 
volatile float ir_sense_distance[4] = {0.0, 0.0, 0.0, 0.0};

// The end time of each interrupt
uint32_t end_micros[4] = {0, 0, 0, 0};
uint32_t start_micros[4] = {0, 0, 0, 0};

#define TIME_DISTANCE_IR_DIVIDER 240.23

void setup_ir_sensors(void);
float get_ir_distance_cm(uint8_t sensor);

/**************************************************************************/
/*!
    @brief IR sensor one interupt service routine function call.
*/
/**************************************************************************/
void ir_sensor_one_isr(void){
    end_micros[0] = micros();
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief IR sensor one interupt service routine function call.
*/
/**************************************************************************/
void ir_sensor_two_isr(void){
    end_micros[1] = micros();
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief IR sensor one interupt service routine function call.
*/
/**************************************************************************/
void ir_sensor_three_isr(void){
    end_micros[2] = micros();
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief IR sensor one interupt service routine function call.
*/
/**************************************************************************/
void ir_sensor_four_isr(void){
    end_micros[3] = micros();
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief Thread function and stack space for our IR sensors. 
*/
/**************************************************************************/
static THD_WORKING_AREA(ir_sensor_calc_thread_wa, 256);
static THD_FUNCTION(ir_sensor_calc_thread, arg){
    (void)arg; 

    for(;;){
        for(uint8_t i = 0; i < 4; i++)
            start_micros[i] = micros();

        // Start IR flash
        digitalWriteFast(IR_EMIT_ONE_GPIO, HIGH);
        digitalWriteFast(IR_EMIT_TWO_GPIO, HIGH);
        digitalWriteFast(IR_EMIT_THREE_GPIO, HIGH);
        digitalWriteFast(IR_EMIT_FOUR_GPIO, HIGH);
        
        // Wait a bit
        chThdSleepMicroseconds(5);

        // END IR Flash
        digitalWriteFast(IR_EMIT_ONE_GPIO, LOW);
        digitalWriteFast(IR_EMIT_TWO_GPIO, LOW);
        digitalWriteFast(IR_EMIT_THREE_GPIO, LOW);
        digitalWriteFast(IR_EMIT_FOUR_GPIO, LOW);

        // Just in case we haven't gotten our response yet... we wait(also gives other threads some more system time)
        chThdSleepMilliseconds(2);

        // Complete IR sensor calculations
        for(uint8_t i = 0; i < 4; i++)
            ir_sense_distance[i] = (end_micros[i] - start_micros[i])/TIME_DISTANCE_IR_DIVIDER;

        // Since we roughly want this to update every 1/100th of a second(unless we need more in the future ofc), 
        // It will sleep a total of 10 milliseconds per cycle. 
        chThdSleepMilliseconds(8);
    }
}

/**************************************************************************/
/*!
    @brief Setup IR sensor thread and interrupts 
*/
/**************************************************************************/
void setup_ir_sensors(void){

    // Setting up our gpio:
    // Setting up our sensor gpio
    pinMode(IR_SENSE_ONE_GPIO, INPUT);
    pinMode(IR_SENSE_TWO_GPIO, INPUT);
    pinMode(IR_SENSE_THREE_GPIO, INPUT);
    pinMode(IR_SENSE_FOUR_GPIO, INPUT);

    // Setting up our emitter gpio
    pinMode(IR_EMIT_ONE_GPIO, OUTPUT);
    pinMode(IR_EMIT_TWO_GPIO, OUTPUT);
    pinMode(IR_EMIT_THREE_GPIO, OUTPUT);
    pinMode(IR_EMIT_FOUR_GPIO, OUTPUT);

    // Setup our interrupts 
    attachInterrupt(digitalPinToInterrupt(IR_SENSE_ONE_GPIO), ir_sensor_one_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_SENSE_TWO_GPIO), ir_sensor_two_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_SENSE_THREE_GPIO), ir_sensor_three_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(IR_SENSE_FOUR_GPIO), ir_sensor_four_isr, RISING);

    // Setup our thread calculation area. 
    chThdCreateStatic(ir_sensor_calc_thread_wa, 
                      sizeof(ir_sensor_calc_thread_wa), 
                      NORMALPRIO + 11, 
                      ir_sensor_calc_thread, 
                      NULL);
}

/**************************************************************************/
/*!
    @brief Get the latest ir distance sensor measurements
    @return float(latest ir distance data)
    @param uint8_t(which sensor are we tryna look at)
*/
/**************************************************************************/
float get_ir_distance_cm(uint8_t sensor){
    return ir_sense_distance[sensor];
}