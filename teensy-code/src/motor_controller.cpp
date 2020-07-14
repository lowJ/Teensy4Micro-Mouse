/*
Author: William Redenbaugh, Jonathan Low
Last Edit Date: 7/3/2020
*/

#include "motor_controller.hpp"

extern void setup_motor_controller(void);

extern void setup_motor_controller(void){

    // Setting up the gpio for our motors. 
    pinMode(MOTOR1_BACKWARD, OUTPUT);
    pinMode(MOTOR1_FORWARD, OUTPUT);
    
    pinMode(MOTOR1_PWM, OUTPUT);
    analogWriteResolution(8);
    
    pinMode(MOTOR2_BACKWARD, OUTPUT);
    pinMode(MOTOR2_FORWARD, OUTPUT);
    pinMode(MOTOR2_PWM, OUTPUT);
}

void set_m1_dir(uint8_t dir){ //0 = backwards, 1 = forward
    if(dir){ //test if these are correct, if not, reverse
        digitalWrite(M1_FORWARD, 1);
        digitalWrite(M1_BACKWARD, 0);
    }
    else{
        digitalWrite(M1_FORWARD, 0);
        digitalWrite(M1_BACKWARD, 1);
    }
}

void set_m2_dir(uint8_t dir){ //0 = backwards, 1 = forward
    if(dir){ //test if these are correct, if not, reverse
        digitalWrite(M2_FORWARD, 1);
        digitalWrite(M2_BACKWARD, 0);
    }
    else{
        digitalWrite(M2_FORWARD, 0);
        digitalWrite(M2_BACKWARD, 1);
    }
}

void set_m1_spd(uint8_t spd){
    analogWrite(M1_SPEED, spd);
}

void set_m2_spd(uint8_t spd){
    analogWrite(M2_SPEED, spd);
}

void m1_stop(){
    digitalWrite(M1_FORWARD, 0);
    digitalWrite(M1_BACKWARD, 0);
    analogWrite(M1_SPEED, 0);
}

void m2_stop(){
    digitalWrite(M2_FORWARD, 0);
    digitalWrite(M2_BACKWARD, 0);
    analogWrite(M2_SPEED, 0);
}

void m1_m2_stop(){
    m1_stop();
    m2_stop();
}
