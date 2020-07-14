/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

#ifndef _MOTOR_CONTROLLER_HPP
#define _MOTOR_CONTROLLER_HPP


#define M1_SPEED 4
#define M1_FORWARD 1
#define M1_BACKWARD 0

#define M2_SPEED 5
#define M2_FORWARD 2
#define M2_BACKWARD 3

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

extern void set_m1_dir(uint8_t dir);

extern void set_m2_dir(uint8_t dir);

extern void set_m1_speed(uint8_t dir);

extern void set_m2_speed(uint8_t dir);

extern void m1_stop();

extern void m2_stop();

extern void m1_m2_stop();

#endif