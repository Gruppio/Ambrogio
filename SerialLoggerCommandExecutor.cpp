//
//  SerialLoggerCommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "SerialLoggerCommandExecutor.h"
#include "Particle.h"

SerialLoggerCommandExecutor::SerialLoggerCommandExecutor(CommandExecutor *commandExecutor)
: CommandExecutorDecorator(commandExecutor) {
}

void SerialLoggerCommandExecutor::executeCommand(Command *command) {
    log(command->getDescription());
    commandExecutor->executeCommand(command);
}
