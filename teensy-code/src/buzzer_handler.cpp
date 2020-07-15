/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

#include "buzzer_handler.hpp"

// Latest buzz frequency. 
uint16_t latest_buzz_freq = 500; 

/**************************************************************************/
/*!
    @brief Enable our buzzer runtime and gpio setup
*/
/**************************************************************************/
extern void setup_buzzer_handler(void){
    pinMode(BUZZER_GPIO, OUTPUT);
    
}

/**************************************************************************/
/*!
    @brief Setup IR sensor thread and interrupts for buzzer
    @param bool whether or not buzzer enabled. 
*/
/**************************************************************************/
extern void en_buzzer(bool buzz){
    if(buzz)
        tone(BUZZER_GPIO, latest_buzz_freq);
    else
        noTone(BUZZER_GPIO);
}

/**************************************************************************/
/*!
    @brief Setting the buzzer tone frequency. 
    @param uint16_t freq
*/
/**************************************************************************/
extern void buzzer_tone(uint16_t freq){
    latest_buzz_freq = freq; 
    tone(BUZZER_GPIO, latest_buzz_freq);
}