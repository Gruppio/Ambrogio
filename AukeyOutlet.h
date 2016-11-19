#ifndef AUKEY_OUTLET_H
#define AUKEY_OUTLET_H

#include "Powered.h"
#include "RCSwitch.h"

class AukeyOutlet : public Powered {
private:
  string outletKey;
  RCSwitch *rcSwitch;

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
