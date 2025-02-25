#include "timer2.h"

ISR(TIMER2_OVF_vect) {
  flg = 1; 
}

void setup_tim2()
{
  TCCR2A = 0;                      // Normal mode (no PWM)
  if(CONST::CTRL::LOW_RATE)
  {
    TCCR2B = _BV(CS22) | _BV(CS21) | _BV(CS20);  // Prescaler = 1024
  }else
  {
    TCCR2B = _BV(CS22) | _BV(CS21);              // Prescaler = 256
  }
  TIMSK2 = _BV(TOIE2);             // Enable overflow interrupt
  TCNT2 = 0;                       // Start counting from 0
}