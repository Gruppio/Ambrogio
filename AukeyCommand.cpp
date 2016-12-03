//
//  AukeyCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "AukeyCommand.h"
#include "Pinout.h"
#include "Particle.h"
#include "AukeyCommandCodes.h"

AukeyCommand::AukeyCommand() {
    description = "Aukey Command";
#if defined(SPARK)
    rcSwitch = new RCSwitch();
    rcSwitch->enableTransmit(PIN_433_MHZ_TX);
#endif
}

AukeyCommand::~AukeyCommand() {
#if defined(SPARK)
    delete rcSwitch;
#endif
}

void AukeyCommand::execute() {

}

void AukeyCommand::transmitCode(int code) {
#if defined(SPARK)
    rcSwitch.send(code, AUKEY_PROTOCOL_CODE);
#endif
}
