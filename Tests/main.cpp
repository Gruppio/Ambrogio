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


// CommandExecutorTests
void commandExecutorTests();
void testCommandExecutorExecuteOnce();
void testCommandExecutorExecuteTwice();

int main(int argc, const char * argv[]) {
    std::cout << "Start Tests\n";
    
    commandExecutorTests();
    
    std::cout << "Done\n\n";
    return 0;
}

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

#endif
