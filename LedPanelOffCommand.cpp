//
//  LedPanelOnCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LedPanelOffCommand.h"
#include "Ambrogio.h"

#define PULSE_LENGHT 250

LedPanelOffCommand::LedPanelOffCommand() {
    this->description = "Turned off led panel";
    pinMode(PIN_LED_PANEL_OFF, INPUT);
}

void LedPanelOffCommand::execute() {
    pinMode(PIN_LED_PANEL_OFF, OUTPUT);
    digitalWrite(PIN_LED_PANEL_OFF, HIGH);
    delay(PULSE_LENGHT);
    pinMode(PIN_LED_PANEL_OFF, INPUT);
}
