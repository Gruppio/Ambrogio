//
//  TestDoubleExecutionCommandExecutor.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifdef TEST

#ifndef TestDoubleExecutionCommandExecutor_h
#define TestDoubleExecutionCommandExecutor_h

#include "CommandExecutorDecorator.h"

class TestDoubleExecutionCommandExecutor: public CommandExecutorDecorator {
public:
    TestDoubleExecutionCommandExecutor(CommandExecutor *commandExecutor);
    virtual ~TestDoubleExecutionCommandExecutor(){};
    virtual void executeCommand(Command *command);
};

#endif /* TestDoubleExecutionCommandExecutor_h */

#endif
