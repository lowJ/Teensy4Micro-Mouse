/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

#include "motor_controller.hpp"

extern void setup_motor_controller(void);

extern void setup_motor_controller(void){
    // Setting up the gpio for our motors. 
    pinMode(MOTOR1_BACKWARD, OUTPUT);
    pinMode(MOTOR1_FORWARD, OUTPUT);
    
    pinMode(MOTOR1_PWM, OUTPUT);
    analogWriteResolution(8);
    
    pinMode(MOTOR2_BACKWARD, OUTPUT);
    pinMode(MOTOR2_FORWARD, OUTPUT);
    pinMode(MOTOR2_PWM, OUTPUT);
}

extern void move_forward(){

}