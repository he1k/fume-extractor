#include "timer1.h"
void setup_tim1()
{
  pinMode(CONST::PINS::PWM_FAN, OUTPUT);
  pinMode(CONST::PINS::PWM_MOS, OUTPUT);
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11);  
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
  ICR1 = 640;
  set_pwm(0, CONST::PINS::PWM_FAN);
  set_pwm(0, CONST::PINS::PWM_MOS);
}

void set_pwm(uint16_t pwm, uint8_t pin)
{
  if(pwm > CONST::PWM::MAX)
  {
    pwm = CONST::PWM::MAX;
  }
  if(pin == CONST::PINS::PWM_FAN)
  {
    OCR1A = pwm;
  }else if(pin == CONST::PINS::PWM_MOS)
  {
    OCR1B = pwm;
  }
}