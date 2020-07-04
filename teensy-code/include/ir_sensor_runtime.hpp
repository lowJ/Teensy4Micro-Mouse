#ifndef _IR_SENSOR_RUNTIME_HPP
#define _IR_SENSOR_RUNTIME_HPP

// Include our main libraries
#include "Arduino.h"
#include "ChRt.h"

#define IR_SENSE_ONE_GPIO 3
#define IR_SENSE_TWO_GPIO 4
#define IR_SENSE_THREE_GPIO 5
#define IR_SENSE_FOUR_GPIO 6

#define IR_EMIT_ONE_GPIO 7
#define IR_EMIT_TWO_GPIO 8
#define IR_EMIT_THREE_GPIO 9
#define IR_EMIT_FOUR_GPIO 10

void setup_ir_sensors(void); 
float get_ir_distance_cm(uint8_t sensor);

#endif 