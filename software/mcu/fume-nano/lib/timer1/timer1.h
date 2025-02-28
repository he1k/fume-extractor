#ifndef TIMER1_H
#define TIMER1_H
#include <Arduino.h>
#include "../../src/constants.h"
void setup_tim1();
void set_pwm(uint16_t pwm, uint8_t cha);

#endif