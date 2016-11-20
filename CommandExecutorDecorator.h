//
//  CommandExecutorDecorator.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandExecutorDecorator_h
#define CommandExecutorDecorator_h

#include "CommandExecutor.h"

class CommandExecutorDecorator: public CommandExecutor {
protected:
    CommandExecutor *commandExecutor;
    
public:
    CommandExecutorDecorator(CommandExecutor *commandExecutor);
    virtual ~CommandExecutorDecorator(){};
    virtual void executeCommand(Command *command);
};

#endif /* CommandExecutorDecorator_h */
