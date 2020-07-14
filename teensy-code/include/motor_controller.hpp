/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
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

extern void setup_motor_controller(void);

#endif