#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdint.h>
namespace CONST
{
  constexpr uint32_t BAUD = 115200;
  namespace PINS
  {
    constexpr uint8_t TACH = 2;
    constexpr uint8_t PWM  = 9;
    constexpr uint8_t REF  = 15;
    constexpr uint8_t PWR  = 4;
  }
  namespace PWM
  {
    constexpr uint16_t MAX = 640;
    constexpr uint16_t MIN = 0;
  }
  namespace CTRL
  {
    constexpr uint8_t LOW_RATE = 0;
  }
}



#endif