#include "tacho.h"

void isr_tach() {
  tacho_cnt++;
}

void setup_tacho()
{
  tacho_cnt = 0;
  attachInterrupt(digitalPinToInterrupt(CONST::PINS::TACH), isr_tach, FALLING);
}