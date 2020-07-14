/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/14/2020
*/

#ifndef _MOTOR_CONTROLLER_HPP
#define _MOTOR_CONTROLLER_HPP

#include "Arduino.h"
#include "ChRt.h"

// GPIO pins for controlling the motor driver. 
#define MOTOR1_BACKWARD 0 
#define MOTOR1_FORWARD  1
#define MOTOR1_PWM 4

#define MOTOR2_BACKWARD 3
#define MOTOR2_FORWARD  2
#define MOTOR2_PWM 5

/**************************************************************************/
/*!
    @brief The direction of our motor: MOTOR_FORWARD or MOTOR_BACKWARD
*/
/**************************************************************************/
enum motor_dir_t{
    MOTOR_FORWARD = 1, 
    MOTOR_BACKWARD = 0 
};

extern void setup_motor_controller(void);
extern void set_m1_dir(motor_dir_t dir);
extern void set_m2_dir(motor_dir_t dir);
extern void set_m1_speed(uint8_t speed);
extern void set_m2_speed(uint8_t speed);
extern void m1_stop();
extern void m2_stop();
extern void m1_m2_stop();

#endif