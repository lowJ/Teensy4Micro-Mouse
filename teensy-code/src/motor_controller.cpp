/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/14/2020
*/

#include "motor_controller.hpp"

extern void setup_motor_controller(void);

/**************************************************************************/
/*!
    @brief Where we call our motor initialization.
*/
/**************************************************************************/
extern void setup_motor_controller(void){

    // Setting up the gpio for our motors. 
    pinMode(MOTOR1_BACKWARD, OUTPUT);
    pinMode(MOTOR1_FORWARD, OUTPUT);
    pinMode(MOTOR1_PWM, OUTPUT);
    
    pinMode(MOTOR2_BACKWARD, OUTPUT);
    pinMode(MOTOR2_FORWARD, OUTPUT);
    pinMode(MOTOR2_PWM, OUTPUT);

    // Adjusting the frequency. 
    analogWriteResolution(8);
    analogWriteFrequency(MOTOR2_PWM, 585937.5);
    analogWriteFrequency(MOTOR1_PWM, 585937.5);
}

/**************************************************************************/
/*!
    @brief Sets the direction of motor m1
    @param motor_dir_t
*/
/**************************************************************************/
void set_m1_dir(motor_dir_t dir){ 
    switch(dir){
    case(MOTOR_FORWARD):
        digitalWrite(MOTOR1_FORWARD, 1);
        digitalWrite(MOTOR1_BACKWARD, 0);
    break;

    case(MOTOR_BACKWARD):
        digitalWrite(MOTOR1_FORWARD, 0);
        digitalWrite(MOTOR1_BACKWARD, 1);
    break;
    }
}

/**************************************************************************/
/*!
    @brief Sets the direction of motor m2
    @param motor_dir_t
*/
/**************************************************************************/
void set_m2_dir(motor_dir_t dir){ 
    switch(dir){
    case(MOTOR_FORWARD):
        digitalWrite(MOTOR2_FORWARD, 1);
        digitalWrite(MOTOR2_BACKWARD, 0);
    break;

    case(MOTOR_BACKWARD):
            digitalWrite(MOTOR2_FORWARD, 0);
            digitalWrite(MOTOR2_BACKWARD, 1);   
    break;
    }
}

/**************************************************************************/
/*!
    @brief Sets the direction of motor m1
    @param motor_dir_t
*/
/**************************************************************************/
void set_m1_speed(uint8_t speed){
    analogWrite(MOTOR1_PWM, speed);
}

/**************************************************************************/
/*!
    @brief Sets the speed of the m2 motor
*/
/**************************************************************************/
void set_m2_speed(uint8_t speed){
    analogWrite(MOTOR2_PWM, speed);
}

/**************************************************************************/
/*!
    @brief Stops the m1 motor
*/
/**************************************************************************/
void m1_stop(){
    digitalWrite(MOTOR1_FORWARD, 0);
    digitalWrite(MOTOR1_BACKWARD, 0);
    analogWrite(MOTOR1_PWM, 0);
}

/**************************************************************************/
/*!
    @brief Stops the m2 motor
*/
/**************************************************************************/
void m2_stop(){
    digitalWrite(MOTOR2_FORWARD, 0);
    digitalWrite(MOTOR2_BACKWARD, 0);
    analogWrite(MOTOR2_PWM, 0);
}

/**************************************************************************/
/*!
    @brief Stops both motors
*/
/**************************************************************************/
void both_motor_stop(){
    m1_stop();
    m2_stop();
}