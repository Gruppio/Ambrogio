//
//  NullCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "NullCommand.h"
#include "Pinout.h"
#include "Particle.h"

NullCommand::NullCommand() {
    description = "Null Command";
    pinMode(PIN_ONBOARD_LED, OUTPUT);
}

void NullCommand::execute() {
    for(int i = 0; i < 3; i++) {
        digitalWrite(PIN_ONBOARD_LED, HIGH);
        delay(300);
        digitalWrite(PIN_ONBOARD_LED, LOW);
        delay(300);
    }
}
