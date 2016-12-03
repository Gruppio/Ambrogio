//
//  LedIndicatorCommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LedIndicatorCommandExecutor.h"
#include "Ambrogio.h"

LedIndicatorCommandExecutor::LedIndicatorCommandExecutor(CommandExecutor *commandExecutor)
: CommandExecutorDecorator(commandExecutor) {
    pinMode(PIN_ONBOARD_LED, OUTPUT);
}

void LedIndicatorCommandExecutor::executeCommand(Command *command) {
    digitalWrite(PIN_ONBOARD_LED, HIGH);
    commandExecutor->executeCommand(command);
    delay(1000);
    digitalWrite(PIN_ONBOARD_LED, LOW);
}
