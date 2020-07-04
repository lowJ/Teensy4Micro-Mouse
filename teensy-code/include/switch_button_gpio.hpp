#ifndef _SWITCH_BUTTON_GPIO_HPP
#define _SWITCH_BUTTON_GPIO_HPP

#include "Arduino.h"
#include "ChRt.h"
#include "lwip_thread.hpp"

#define PUSH_SW1_GPIO 11
#define PUSH_SW_GPIO 14

extern void setup_switch_button_gpio(void);

#endif