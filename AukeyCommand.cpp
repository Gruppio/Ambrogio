//
//  AukeyCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "AukeyCommand.h"

AukeyCommand::AukeyCommand() {
    description = "Aukey Command";
    pinMode(PIN_433_MHZ_TX, OUTPUT);
    rcSwitch = new RCSwitch();
    rcSwitch->enableTransmit(PIN_433_MHZ_TX);
}

AukeyCommand::~AukeyCommand() {
    delete rcSwitch;
}

void AukeyCommand::execute() {
}

void AukeyCommand::transmitCode(unsigned long code) {
    rcSwitch->send(code, AUKEY_PROTOCOL_CODE);
}
