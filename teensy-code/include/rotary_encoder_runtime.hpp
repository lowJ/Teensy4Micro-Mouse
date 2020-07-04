#ifndef _ROTARY_ENCODER_RUNTIME_HPP
#define _ROTARY_ENCODER_RUNTIME_HPP

// Including main libraries 
#include "Arduino.h"
#include "ChRt.h"

#define LEFT_ROTARY_PIN_ISR_GPIO 2
#define RIGHT_ROTARY_PIN_ISR_GPIO 1

extern void setup_rotatary_encoders(void);
float get_left_wheel_rpm(void);
float get_right_wheel_rpm(void);

#endif 