/*
Author: William Redenbaugh
Last Edit Date: 7/3/2020
*/

#include "led_matrix_runtime.hpp"

MUTEX_DECL(led_matrix_mutex);
thread_t *led_runtime_handler;

#define CHANGE_MATRIX_BITMASK 0 
eventmask_t event_mask;  
volatile bool interrupt_animation = false; 

/**************************************************************************/
/*!
    @brief Thread function and stack space for our led matrix stuff. 
*/
/**************************************************************************/
static THD_WORKING_AREA(led_matrix_thread_wa, 4096);
static THD_FUNCTION(led_matrix_thread, arg){
    (void)arg; 
    // So we can access the thread handlers. 
    led_runtime_handler = chThdGetSelfX();

    _start_ws2812b_matrix();
    bool animation_changed = 0;

    for(;;){
        chThdSleepSeconds(1);
    }
}

/**************************************************************************/
/*!
    @brief Allows us to setup our led strip/matrix thread.  
*/
/**************************************************************************/
extern void start_led_strip_thread(void){
    chThdCreateStatic(led_matrix_thread_wa, 
                      sizeof(led_matrix_thread_wa), 
                      NORMALPRIO + 3, 
                      led_matrix_thread, 
                      NULL);
}