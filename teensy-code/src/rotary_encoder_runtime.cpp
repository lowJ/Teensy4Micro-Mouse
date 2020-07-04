#include "rotary_encoder_runtime.hpp"

void left_rotary_encoder_isr(void);
void right_rotary_encoder_isr(void);

void setup_rotary_encoders(void);

float get_left_wheel_rpm(void);
float get_right_wheel_rpm(void);

// Latest rotary count data. 
volatile uint32_t right_rotary_increment = 0; 
volatile uint32_t left_rotary_increment = 0; 

// Latest RPM data
volatile float left_rotary_rpm = 0.0; 
volatile float right_rotary_rpm = 0.0; 


/**************************************************************************/
/*!
    @brief Left motor rotary ecoder interrupt function call
*/
/**************************************************************************/
void left_rotary_encoder_isr(void){
    left_rotary_increment++; 
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief Right motor rotary encoder interrupt function call
*/
/**************************************************************************/
void right_rotary_encoder_isr(void){
    right_rotary_increment++;
    asm("dsb");
}

/**************************************************************************/
/*!
    @brief Thread function and stack space where we will deal with rotary encoder calculations. 
*/
/**************************************************************************/
static THD_WORKING_AREA(rotary_encoder_calc_wa, 256);
static THD_FUNCTION(rotary_encoder_calc, arg){
    (void)arg; 

    for(;;){
        chThdSleepSeconds(1);
    }
}

/**************************************************************************/
/*!
    @brief Allows us to setup the rotary encoder thread and interrupts
*/
/**************************************************************************/
extern void setup_rotatary_encoders(void){
    // Attach interrupts to our gpio pins
    attachInterrupt(digitalPinToInterrupt(LEFT_ROTARY_PIN_ISR_GPIO), left_rotary_encoder_isr, RISING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ROTARY_PIN_ISR_GPIO), right_rotary_encoder_isr, RISING);

    // Generate our thread and stack space for calculating rotary encoder RPMS and such
    chThdCreateStatic(rotary_encoder_calc_wa, 
                      sizeof(rotary_encoder_calc_wa), 
                      NORMALPRIO + 10, 
                      rotary_encoder_calc, 
                      NULL);
}

/**************************************************************************/
/*!
    @brief Get the latest left wheel RPM measurments
    @return float
*/
/**************************************************************************/
float get_left_wheel_rpm(void){
    return left_rotary_rpm;
}

/**************************************************************************/
/*!
    @brief Get the latest right wheel RPM measurments
*/
/**************************************************************************/
float get_right_Wheel_rpm(void){
    return right_rotary_rpm; 
} 