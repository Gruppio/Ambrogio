//
//  CommandExecutorDecorator.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "CommandExecutorDecorator.h"

CommandExecutorDecorator::CommandExecutorDecorator(CommandExecutor *commandExecutor)
:commandExecutor(commandExecutor) {
}

void CommandExecutorDecorator::executeCommand(Command *command) {
    commandExecutor->executeCommand(command);
}
