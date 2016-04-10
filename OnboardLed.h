#ifndef ONBOARD_LED_H
#define ONBOARD_LED_H

#include "Powered.h"
#include "Pinout.h"

class OnboardLed : public Powered {
public:
  OnboardLed() {
    pinMode(PIN_ONBOARD_LED, OUTPUT);
    digitalWrite(PIN_ONBOARD_LED, LOW);
  }

  void turnOn() {
    digitalWrite(PIN_ONBOARD_LED, HIGH);
  }

  void turnOff() {
    digitalWrite(PIN_ONBOARD_LED, LOW);
  }
};

#endif
