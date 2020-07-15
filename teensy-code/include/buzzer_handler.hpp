/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

#ifndef _BUZZER_HANDLER_HPP
#define _BUZZER_HANDLER_HPP

// Include Main files 
#include "Arduino.h"
#include "ChRt.h"

// GPIO for the buzzer. 
#define BUZZER_GPIO 13

extern void setup_buzzer_handler(void);
extern void en_buzzer(bool buzz); 
extern void buzzer_tone(uint16_t freq);

#endif