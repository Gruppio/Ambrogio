//
//  LedPanelOnCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LedPanelOnCommand.h"
#include "Ambrogio.h"

#define PULSE_LENGHT 250

LedPanelOnCommand::LedPanelOnCommand() {
    this->description = "Turned on led panel";
    pinMode(PIN_LED_PANEL_ON, INPUT);
}

void LedPanelOnCommand::execute() {
    pinMode(PIN_LED_PANEL_ON, OUTPUT);
    digitalWrite(PIN_LED_PANEL_ON, HIGH);
    delay(PULSE_LENGHT);
    pinMode(PIN_LED_PANEL_ON, INPUT);
}
