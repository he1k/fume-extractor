#include "timer1.h"
void setup_tim1()
{
  pinMode(CONST::PINS::PWM, OUTPUT);
  pinMode(10, OUTPUT);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);  
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1 = 640;
  set_pwm(0);
}

void set_pwm(uint16_t pwm)
{
  if(pwm > CONST::PWM::MAX)
  {
    OCR1A = CONST::PWM::MAX;
  }else
  {
    OCR1A = pwm;
  }
}