#ifndef MCP9700_H
#define MCP9700_H

#include "Thermometer.h"
#include "Pinout.h"

class MCP9700 : public Thermometer {
public:
  double getTemperature() {
    int temperatureValue = analogRead(PIN_THERMOMETER);
    double temperature = (((temperatureValue * 3.3)/4095) - 0.5) * 100;
    return temperature;
  }
};

#endif
