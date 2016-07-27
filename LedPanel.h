#ifndef LED_PANEL_H
#define LED_PANEL_H

#include "Powered.h"
#include "Pinout.h"

#define PULSE_LENGHT 250

class LedPanel : public Powered {
public:

  LedPanel() {
    pinMode(PIN_LED_PANEL_ON, INPUT);
    pinMode(PIN_LED_PANEL_OFF, INPUT);
  }

  void turnOn() {
    toggleButton(PIN_LED_PANEL_ON);
  }

  void turnOff() {
    toggleButton(PIN_LED_PANEL_OFF);
  }

  void toggleButton(int pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(PULSE_LENGHT);
    pinMode(pin, INPUT);
  }

};

#endif
