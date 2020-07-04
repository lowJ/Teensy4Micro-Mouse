/*
Author: William Redenbaugh
Last Edit Date: 7/3/2020
*/


#ifndef _LED_MATRIX_HANDLER_HPP
#define _LED_MATRIX_HANDLER_HPP

#include "ChRt.h"
#include "WS2812Serial.h"
#include "Arduino.h"
#include "hsv_rgb_conv.hpp"

// Usable pins:
// Teensy 4.0:  1, 8, 14, 17, 20, 24, 29, 39

// GPIO pin that we will put our led strip on. 
#define LED_MATRIX_GPIO 1
// GPIO pin that we will put our underglow on strip on. 
#define UNDERGLOW_STRIP_GPIO 14

// For us on our prototyping board. 
#define NUM_MATRIX_LEDS 12
#define UNDERGLOW_NUM_LEDS 4
enum led_macro_t{
    LED_MACRO_0_POS = 0,   
    LED_MACRO_1_POS = 1,   
    LED_MACRO_2_POS = 2,  
    LED_MACRO_3_POS = 3,   
    LED_MACRO_4_POS = 4,   
    LED_MACRO_5_POS = 5,   
    LED_MACRO_6_POS = 6,   
    LED_MACRO_7_POS = 7,   
    LED_MACRO_8_POS = 8,   
    LED_MACRO_9_POS = 9,   
    LED_MACRO_10_POS = 10,   
    LED_MACRO_11_POS = 11,   
    LED_MACRO_12_POS = 12,   
    LED_MACRO_13_POS = 13,   
    LED_MACRO_14_POS = 14,   
    LED_MACRO_15_POS = 15
};

extern void _start_ws2812b_matrix(void);
extern void _update_ws2812b_matrix(void);

extern void _set_ws2812b_macro(led_macro_t led_macro,  uint8_t r, uint8_t g, uint8_t b);
extern void _set_ws2812b_macro_hsv(led_macro_t led_macro, uint8_t h, uint8_t s, uint8_t v);

extern void _set_ws2812b_led_all(uint8_t r, uint8_t g, uint8_t b);
extern void _set_ws2812b_led_all_hsv(uint8_t h, uint8_t s, uint8_t v);

#endif 