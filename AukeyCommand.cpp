//
//  AukeyCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "AukeyCommand.h"

//pinMode(PIN_433_MHZ_TX, OUTPUT);
//rcSwitch = rcSwitch;
//rcSwitch->enableTransmit(PIN_433_MHZ_TX);

AukeyCommand::AukeyCommand(RemoteController *remoteController, REMOTE_CONTROLLER_TRANSMIT_TYPE code, const char *description) {
    remoteController = remoteController;
    code = code;
    description = description;
}

void AukeyCommand::execute() {
    remoteController->transmit(code);
}
