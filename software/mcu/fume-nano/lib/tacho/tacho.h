#ifndef TACHO_H
#define TACHO_H
#include <Arduino.h>
#include "../../src/constants.h"
extern volatile uint16_t tacho_cnt;
void isr_tach();
void setup_tacho();

#endif