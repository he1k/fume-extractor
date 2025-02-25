#ifndef TIMER2_H
#define TIMER2_H
#include <Arduino.h>
#include "../../src/constants.h"

extern volatile uint8_t flg;
ISR(TIMER2_OVF_vect);
void setup_tim2();



#endif