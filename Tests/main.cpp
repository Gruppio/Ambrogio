//
//  main.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 19/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#if !defined(SPARK)

#include <iostream>
#include <assert.h>
#include "Command.h"
#include "CommandsName.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "TestCommand.h"
#include "TestDoubleExecutionCommandExecutor.h"
#include "SerialLoggerCommandExecutor.h"
#include "LedPanelOnCommand.h"
#include "LedPanelOffCommand.h"
#include "LivingRoomLampOnCommand.h"
#include "LivingRoomLampOffCommand.h"


// CommandExecutorTests
void commandExecutorTests();
void testCommandExecutorExecuteOnce();
void testCommandExecutorExecuteTwice();

// CommandExecutorDecoratedTests
void commandExecutorDecoratedTests();
void testCommandExecutorDecoratorExecutedDouble();
void testCommandExecutorLogger();

// CommandFactory Tests
void commandFactoryTests();
void testCommandFactoryNullCommand();
void testCommandFactoryLedPanelOn();
void testCommandFactoryLedPanelOff();
void testCommandFactoryLivingRoomLampOn();
void testCommandFactoryLivingRoomLampOff();



int main(int argc, const char * argv[]) {
    std::cout << "Start Tests\n";
    
    commandExecutorTests();
    commandExecutorDecoratedTests();
    commandFactoryTests();
    
    std::cout << "Done\n\n";
    return 0;
}

///////////////////////////////////////////////

void commandExecutorTests() {
    testCommandExecutorExecuteOnce();
    testCommandExecutorExecuteTwice();
}

void testCommandExecutorExecuteOnce() {
    TestCommand *command = new TestCommand();
    CommandExecutor *commandExecutor = new CommandExecutor();
    
    commandExecutor->executeCommand(command);
    assert(command->numberOfExecutions == 1);
    
    delete command;
    delete commandExecutor;
}

void testCommandExecutorExecuteTwice() {
    TestCommand *command = new TestCommand();
    CommandExecutor *commandExecutor = new CommandExecutor();
    
    commandExecutor->executeCommand(command);
    commandExecutor->executeCommand(command);
    assert(command->numberOfExecutions == 2);
    
    delete command;
    delete commandExecutor;
}

///////////////////////////////////////////////

void commandExecutorDecoratedTests() {
    testCommandExecutorDecoratorExecutedDouble();
    testCommandExecutorLogger();
}

void testCommandExecutorDecoratorExecutedDouble() {
    TestCommand *command = new TestCommand();
    CommandExecutor *commandExecutor = new CommandExecutor();
    CommandExecutor *commandExecutorDecorated = new TestDoubleExecutionCommandExecutor(commandExecutor);
    
    commandExecutorDecorated->executeCommand(command);
    assert(command->numberOfExecutions == 2);
    
    delete command;
    delete commandExecutorDecorated;
    delete commandExecutor;
}

void testCommandExecutorLogger() {
    TestCommand *command = new TestCommand();
    CommandExecutor *commandExecutor = new CommandExecutor();
    CommandExecutor *commandExecutorLogger = new SerialLoggerCommandExecutor(commandExecutor);
    
    commandExecutorLogger->executeCommand(command);
    
    delete command;
    delete commandExecutorLogger;
    delete commandExecutor;
}

///////////////////////////////////////////////

void commandFactoryTests() {
    testCommandFactoryNullCommand();
    testCommandFactoryLedPanelOn();
    testCommandFactoryLedPanelOff();
    testCommandFactoryLivingRoomLampOn();
    testCommandFactoryLivingRoomLampOff();
}

void testCommandFactoryNullCommand() {
    CommandFactory *commandFactory = new CommandFactory();
    Command *command = commandFactory->createCommand("wrong command name");
    NullCommand *nullCommand = dynamic_cast<NullCommand*>(command);
    
    assert(nullCommand != NULL);
    
    delete command;
    delete commandFactory;
}

void testCommandFactoryLedPanelOn() {
    CommandFactory *commandFactory = new CommandFactory();
    Command *command = commandFactory->createCommand(LED_PANEL_ON);
    LedPanelOnCommand *ledPanelOnCommand = dynamic_cast<LedPanelOnCommand*>(command);
    
    assert(ledPanelOnCommand != NULL);
    
    delete command;
    delete commandFactory;
}

void testCommandFactoryLedPanelOff() {
    CommandFactory *commandFactory = new CommandFactory();
    Command *command = commandFactory->createCommand(LED_PANEL_OFF);
    LedPanelOffCommand *ledPanelOffCommand = dynamic_cast<LedPanelOffCommand*>(command);
    
    assert(ledPanelOffCommand != NULL);
    
    delete command;
    delete commandFactory;
}

void testCommandFactoryLivingRoomLampOn() {
    CommandFactory *commandFactory = new CommandFactory();
    Command *command = commandFactory->createCommand(LIVING_ROOM_LAMP_ON);
    LivingRoomLampOnCommand *livingRoomLampOnCommand = dynamic_cast<LivingRoomLampOnCommand*>(command);
    
    assert(livingRoomLampOnCommand != NULL);
    
    delete command;
    delete commandFactory;
}

void testCommandFactoryLivingRoomLampOff() {
    CommandFactory *commandFactory = new CommandFactory();
    Command *command = commandFactory->createCommand(LIVING_ROOM_LAMP_OFF);
    LivingRoomLampOffCommand *livingRoomLampOffCommand = dynamic_cast<LivingRoomLampOffCommand*>(command);
    
    assert(livingRoomLampOffCommand != NULL);
    
    delete command;
    delete commandFactory;
}


#endif



