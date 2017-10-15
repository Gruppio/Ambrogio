//
//  NullCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "NullCommand.h"
#include "Ambrogio.h"

#define DELAY 150

NullCommand::NullCommand(): Command("Null Command") {
    pinMode(PIN_ONBOARD_LED, OUTPUT);
}

void NullCommand::execute() {
    for(int i = 0; i < 3; i++) {
        digitalWrite(PIN_ONBOARD_LED, HIGH);
        delay(DELAY);
        digitalWrite(PIN_ONBOARD_LED, LOW);
        delay(DELAY);
    }
}
