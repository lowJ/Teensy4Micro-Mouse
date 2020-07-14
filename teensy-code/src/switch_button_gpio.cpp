#include "switch_button_gpio.hpp"

struct{
    uint8_t sw1_latest_status = 0; 
    uint8_t sw_latest_status = 0;
}gpio_read;

extern void setup_switch_button_gpio(void);
void read_gpio(void *params);

/**************************************************************************/
/*!
    @brief Task that reads the gpio state periodically
*/
/**************************************************************************/
void read_gpio(void *params){
    (void)params; 
    
    gpio_read.sw_latest_status = digitalReadFast(PUSH_SW_GPIO);
    gpio_read.sw1_latest_status = digitalReadFast(PUSH_SW1_GPIO);
}

/**************************************************************************/
/*!
    @brief Allows us to setup our switch gpio and threading
*/
/**************************************************************************/
extern void setup_switch_button_gpio(void){
    void *args = NULL; 
    
    // Setup GPIO
    pinMode(PUSH_SW1_GPIO, INPUT_PULLUP);
    pinMode(PUSH_SW_GPIO, INPUT_PULLUP);

    // add reading gpio to low priority work task. 
    add_lwip_task(&read_gpio, args, chTimeMS2I(100));
}