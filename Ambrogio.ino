#include "WifiUser.h"
#include "Pinout.h"
#include "MCP9700.h"
#include "LedPanel.h"
#include "OnboardLed.h"
#include "WifiCredentials.h"
#include "RCSwitch.h"

#define LOOP_TIME 1000

WifiUser wifiUsers[]  = { WifiUser(IPAddress(192,168,0,5), "Gruppio"),
                          WifiUser(IPAddress(192,168,0,3), "Fede") };

RCSwitch *rcSwitch        = new RCSwitch();
Powered *led              = new OnboardLed();
Powered *ledPanel         = new LedPanel();
Thermometer *thermometer  = new MCP9700();

double temperature = 0;

void setup() {
    Particle.variable("Temperature", temperature);
    Particle.function("turnLightOn", turnLedPanelOn);
    Particle.function("turnLightOff", turnLedPanelOff);
    WiFi.setCredentials(SSID, PASSWORD);
    Serial.begin(9600);
    Serial.println("Hello World!");
}

void loop() {
/*
    for( int userIndex = 0; userIndex < arraySize(wifiUsers); userIndex++ ) {
    }
*/
  Serial.printlnf("System version: %s", System.version().c_str());
  readTemperature();
  delay(LOOP_TIME);
}

void readTemperature() {
  temperature = thermometer->getTemperature();
}

int turnLedPanelOn(String command) {
  led->turnOn();
  ledPanel->turnOn();
  led->turnOff();
  return 0;
}

int turnLedPanelOff(String command) {
  led->turnOn();
  ledPanel->turnOff();
  led->turnOff();
  return 0;
}
