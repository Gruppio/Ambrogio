//#include "WifiUser.h"
#include "MCP9700.h"
#include "WifiCredentials.h"
#include "Command.h"
#include "CommandFactory.h"
#include "CommandExecutor.h"
#include "SerialLoggerCommandExecutor.h"
#include "LedIndicatorCommandExecutor.h"
#include "ParticleEventCommandExecutor.h"
#include "RemoteController.h"
#include "RemoteController433.h"
#include "ApplianceStateRecorder.h"
#include "ApplianceNameFromCommandNameFactory.h"

#define LOOP_TIME 1000

/*WifiUser wifiUsers[]  = { WifiUser(IPAddress(192,168,0,5), "Gruppio"),
                          WifiUser(IPAddress(192,168,0,3), "Fede") };*/

Thermometer *thermometer = new MCP9700();
RCSwitch *rcSwitch = new RCSwitch();
RemoteController *remoteController = new RemoteController433(rcSwitch);
ApplianceStateRecorder *applianceStateRecorder = new ApplianceStateRecorder();
ApplianceNameFromCommandNameFactory *applianceNameFactory = new ApplianceNameFromCommandNameFactory();
CommandFactory *commandFactory = new CommandFactory(remoteController, applianceStateRecorder, applianceNameFactory);
CommandExecutor *commandExecutor = new ParticleEventCommandExecutor(new SerialLoggerCommandExecutor(new LedIndicatorCommandExecutor(new CommandExecutor())));

double temperature = 0;
int hourOld = 0;

void setup() {
    pinMode(PIN_433_MHZ_TX, OUTPUT);
    rcSwitch->enableTransmit(PIN_433_MHZ_TX);
    rcSwitch->setPulseLength(170);
    rcSwitch->setRepeatTransmit(20);
    Particle.variable("temperature", temperature);
    Particle.function("execute", execute);
    Particle.function("status", status);
    WiFi.setCredentials(SSID, PASSWORD);
    Serial.begin(9600);
}

void loop() {
  readTemperature();
  if (shouldPublishTemperature()) {
    Particle.publish("temperature", String::format("%.1f", temperature), PRIVATE);
  }
  delay(LOOP_TIME);
}

void readTemperature() {
  temperature = thermometer->getTemperature();
}

bool shouldPublishTemperature() {
  int hour = Time.hour();
  bool shouldPublish = (hourOld != hour);
  hourOld = hour;
  return shouldPublish;
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

int status(String message) {
  return applianceStateRecorder->getApplianceState(message);
}
