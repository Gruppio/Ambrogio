//#include "WifiUser.h"
#include "MCP9700.h"
#include "WifiCredentials.h"
#include "Command.h"
#include "CommandFactory.h"
#include "CommandExecutor.h"
#include "SerialLoggerCommandExecutor.h"
#include "LedIndicatorCommandExecutor.h"

#define LOOP_TIME 1000

/*WifiUser wifiUsers[]  = { WifiUser(IPAddress(192,168,0,5), "Gruppio"),
                          WifiUser(IPAddress(192,168,0,3), "Fede") };*/

Thermometer *thermometer  = new MCP9700();
CommandFactory *commandFactory = new CommandFactory();
CommandExecutor *commandExecutor = new SerialLoggerCommandExecutor(new LedIndicatorCommandExecutor(new CommandExecutor()));

double temperature = 0;

void setup() {
    Particle.variable("temperature", temperature);
    Particle.function("execute", execute);
    WiFi.setCredentials(SSID, PASSWORD);
    Serial.begin(9600);
}

void loop() {
  readTemperature();
  delay(LOOP_TIME);
}

void readTemperature() {
  temperature = thermometer->getTemperature();
}

int execute(String message) {
  Command *command = commandFactory->createCommand(message);
  if (command == 0) {
    return -1;
  }

  commandExecutor->executeCommand(command);
  delete command;
  return 0;
}
