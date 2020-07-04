/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

// Arduino and ChibiOS Libraries 
#include "Arduino.h"
#include "ChRt.h"

// Our own modules 
#include "lwip_thread.hpp"

// Our runtime files. 
#include "led_matrix_runtime.hpp"
#include "main_logic.hpp"
#include "buzzer_handler.hpp"
#include "rotary_encoder_runtime.hpp"
#include "ir_sensor_runtime.hpp"
#include "motor_controller.hpp"

/**************************************************************************/
/*!
    @brief Where we call our chibiOS initialization functions.
*/
/**************************************************************************/
void chibiSetup(void){
  // This is technically a runtime thread but it holds a bunch of subthreads to do work 
  setup_lwip_thread();

  // Setting up our other primary sensor and controlling modules
  setup_buzzer_handler();
  setup_ir_sensors();
  setup_motor_controller();
  setup_rotatary_encoders();
  
  chThdSleepSeconds(2);
  // Since this is our primary logic unit, we wanna start this one last
  setup_main_logic();
}

/**************************************************************************/
/*!
    @brief All of our setup happens in here. This is where to start up chibiOS. 
*/
/**************************************************************************/
void setup() {
  // We do all of our setup in here. 
  chBegin(chibiSetup);  
}


// Currently doing nothing atm. 
void loop() {
  chThdSleepSeconds(1);
}