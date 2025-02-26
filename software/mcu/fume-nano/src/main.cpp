#include <Arduino.h>
#include <stdlib.h>
#include "constants.h"
#include "timer1.h"
#include "timer2.h"
#include "tacho.h"
// #################################################
// ## GLOBAL VARIABLES
volatile uint16_t tacho_cnt;
volatile uint16_t tacho_cnt_prev;
volatile uint8_t flg;
volatile uint8_t cnt;


void setup()
{
  Serial.begin(CONST::BAUD);
  while(!Serial){delay(10);}
  Serial.println("Serial setup.");
  setup_tim1();
  Serial.println("Timer 1 setup for 25 kHz PWM.");
  setup_tacho();
  Serial.println("Tachometer setup.");
  setup_tim2();
  Serial.println("Timer 1 setup for control loop.");
  sei();
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  set_pwm(0);
  pinMode(CONST::PINS::REF, INPUT);
  pinMode(CONST::PINS::PWR, OUTPUT);
  uint8_t on = 0;
  set_pwm((uint16_t)(1.0*6.4));
  OCR1B = 500;
  while(1)
  {
    digitalWrite(CONST::PINS::PWR, on);
    on = !on;
    delayMicroseconds(2);
  }
  cnt = 0;
}

void loop() {
  if(flg)
  {
    flg = 0;
    uint16_t in = analogRead(CONST::PINS::REF);
    uint16_t pwm = (uint16_t)(in*0.3125f);
    set_pwm(pwm);
    //set_pwm(0);
    cnt++;
    if(cnt == 24)
    {
      int16_t tacho_d = abs(tacho_cnt - tacho_cnt_prev);
      tacho_cnt_prev = tacho_cnt;
      Serial.print("A1 = "); Serial.print(in);
      Serial.print(",\t pwm = "); Serial.print(pwm); 
      Serial.print(",\t tach = ");Serial.println(tacho_d);
      cnt = 0;
    }
  }
}







