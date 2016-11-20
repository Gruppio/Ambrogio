//
//  main.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 19/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#if defined(SPARK)
#else

#include <iostream>
#include <assert.h>
#include "Command.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"
#include "TestCommand.h"
#include "TestDoubleExecutionCommandExecutor.h"
#include "SerialLoggerCommandExecutor.h"


// CommandExecutorTests
void commandExecutorTests();
void testCommandExecutorExecuteOnce();
void testCommandExecutorExecuteTwice();

// CommandExecutorDecoratedTests
void commandExecutorDecoratedTests();
void testCommandExecutorDecoratorExecutedDouble();
void testCommandExecutorLogger();


int main(int argc, const char * argv[]) {
    std::cout << "Start Tests\n";
    
    commandExecutorTests();
    commandExecutorDecoratedTests();
    
    std::cout << "Done\n\n";
    return 0;
}

void commandExecutorTests() {
    testCommandExecutorExecuteOnce();
    testCommandExecutorExecuteTwice();
}

void commandExecutorDecoratedTests() {
    testCommandExecutorDecoratorExecutedDouble();
    testCommandExecutorLogger();
}


///////////////////////////////////////////////


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

#endif



