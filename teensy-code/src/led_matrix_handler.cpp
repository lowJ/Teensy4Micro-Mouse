#include "led_matrix_handler.hpp"

// SERIAL DMA FOR LED MATRIX BEGIN // 

// default number of matrix_leds. 
const int num_matrix_led = NUM_MATRIX_LEDS;
// Default GPIO value. 
uint8_t led_matrix_gpio = LED_MATRIX_GPIO;

byte matrix_drawing_memory[num_matrix_led*3];         //  3 bytes per LED for RGB
DMAMEM byte matrix_display_memory[num_matrix_led*12]; // 12 bytes per LED for RGB

WS2812Serial matrix_leds = WS2812Serial(num_matrix_led, matrix_display_memory, matrix_drawing_memory, led_matrix_gpio, WS2812_GRB);

// SERIAL DMA FOR LED MATRIX END // 


// Will allow us to start up our matrix from the runtime. 
extern void _start_ws2812b_matrix(void);
extern void _update_ws2812b_matrix(void);

extern void _set_ws2812b_macro(led_macro_t led_macro,  uint8_t r, uint8_t g, uint8_t b);
extern void _set_ws2812b_macro_hsv(led_macro_t led_macro, uint8_t h, uint8_t s, uint8_t v);

extern void _set_ws2812b_led_all(uint8_t r, uint8_t g, uint8_t b);
extern void _set_ws2812b_led_all_hsv(uint8_t h, uint8_t s, uint8_t v);

/**************************************************************************/
/*!
    @brief Set's up the ws2812b rgb matrix so it's ready for us to push data!
*/
/**************************************************************************/
extern void _start_ws2812b_matrix(void){
    matrix_leds.begin();
    matrix_leds.show();
}

/**************************************************************************/
/*!
    @brief Allows us to set all of our matrix leds to a specific HSV value
    @param led_macro_t (which led are we controlling)
    @param uint8_t(red)
    @param uint8_t(green)
    @param uint8_t(blue)
*/
/**************************************************************************/
extern void _set_ws2812b_macro(led_macro_t led_macro,  uint8_t r, uint8_t g, uint8_t b){
    switch (led_macro){
    case(LED_MACRO_0_POS):
        matrix_leds.setPixelColor(0, r, g, b);
    break;
    case(LED_MACRO_1_POS):
        matrix_leds.setPixelColor(1, r, g, b);
    break;
    case(LED_MACRO_2_POS):
        matrix_leds.setPixelColor(2, r, g, b);
    break;
    case(LED_MACRO_3_POS):
        matrix_leds.setPixelColor(3, r, g, b);
    break;
    case(LED_MACRO_4_POS):
        matrix_leds.setPixelColor(5, r, g, b);
    break;
    case(LED_MACRO_5_POS):
        matrix_leds.setPixelColor(4, r, g, b);
    break;
    case(LED_MACRO_7_POS):
        matrix_leds.setPixelColor(7, r, g, b);
    break;
    case(LED_MACRO_6_POS):
        matrix_leds.setPixelColor(6, r, g, b);
    break;
    case(LED_MACRO_8_POS):
        matrix_leds.setPixelColor(11, r, g, b);
    break;
    case(LED_MACRO_9_POS):
        matrix_leds.setPixelColor(10, r, g, b);
    break;
    case(LED_MACRO_10_POS):
        matrix_leds.setPixelColor(9, r, g, b);
    break;
    case(LED_MACRO_11_POS):
        matrix_leds.setPixelColor(8, r, g, b);
    break;
    default:
    break;
    }
}


/**************************************************************************/
/*!
    @brief Allows us to set all of our matrix leds to a specific HSV value
    @param led_macro_t (which LED are we controlling. )
    @param uint8_t(hue)
    @param uint8_t(saturation)
    @param uint8_t(value)
*/
/**************************************************************************/
extern void _set_ws2812b_macro_hsv(led_macro_t led_macro, uint8_t h, uint8_t s, uint8_t v){
    HsvColor hsv; 
    hsv.h = h; 
    hsv.s = s; 
    hsv.v = v; 
    RgbColor rgb = HsvToRgb(hsv);

    _set_ws2812b_macro(led_macro, rgb.r, rgb.g, rgb.b);
}

/**************************************************************************/
/*!
    @brief Allows us to set all of our matrix leds to a specific HSV value
    @param uint8_t(blue)
    @param uint8_t(green)
    @param uint8_t(blue)
*/
/**************************************************************************/
extern void _set_ws2812b_led_all(uint8_t r, uint8_t g, uint8_t b){
    for(uint8_t i = 0; i < NUM_MATRIX_LEDS; i++)
        _set_ws2812b_macro((led_macro_t)i, r, g, b);
}

/**************************************************************************/
/*!
    @brief Allows us to set all of our matrix leds to a specific HSV value
    @param uint8_t(hue)
    @param uint8_t(saturation)
    @param uint8_t(value)
*/
/**************************************************************************/
extern void _set_ws2812b_led_all_hsv(uint8_t h, uint8_t s, uint8_t v){
    for(uint8_t i = 0; i < NUM_MATRIX_LEDS; i++)
        _set_ws2812b_macro_hsv((led_macro_t)i, h, s, v);
}

/**************************************************************************/
/*!
    @brief We have to update our ws2812b matrix leds
*/
/**************************************************************************/
extern void _update_ws2812b_matrix(void){
    matrix_leds.show();
}