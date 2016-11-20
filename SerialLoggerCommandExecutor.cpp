//
//  SerialLoggerCommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "SerialLoggerCommandExecutor.h"

#if defined(SPARK)
#include "application.h"
#define log(message) Serial.println(message);
#else
#include <iostream>
#define log(message) std::cout << message << std::endl;
#endif

SerialLoggerCommandExecutor::SerialLoggerCommandExecutor(CommandExecutor *commandExecutor)
: CommandExecutorDecorator(commandExecutor) {
}

void SerialLoggerCommandExecutor::executeCommand(Command *command) {
    log(command->description);
    commandExecutor->executeCommand(command);
}
