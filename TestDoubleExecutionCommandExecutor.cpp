//
//  TestDoubleExecutionCommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifdef TEST

#include "TestDoubleExecutionCommandExecutor.h"

TestDoubleExecutionCommandExecutor::TestDoubleExecutionCommandExecutor(CommandExecutor *commandExecutor)
: CommandExecutorDecorator(commandExecutor) {
}

void TestDoubleExecutionCommandExecutor::executeCommand(Command *command) {
    command->execute();
    commandExecutor->executeCommand(command);
}

#endif
