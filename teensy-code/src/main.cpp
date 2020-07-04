// Arduino and ChibiOS Libraries 
#include "Arduino.h"
#include "ChRt.h"

// Our own modules 
#include "lwip_thread.hpp"

// Other libraries

// Our runtime files. 
#include "led_matrix_runtime.hpp"

/**************************************************************************/
/*!
    @brief Where we call our chibiOS initialization functions.
*/
/**************************************************************************/
void chibiSetup(void){
  // This is technically a runtime thread but it holds a bunch of subthreads to do work 
  setup_lwip_thread();

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