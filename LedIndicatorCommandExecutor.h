//
//  LedIndicatorCommandExecutor.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LedIndicatorCommandExecutor_h
#define LedIndicatorCommandExecutor_h

#include "CommandExecutorDecorator.h"

class LedIndicatorCommandExecutor: public CommandExecutorDecorator {
public:
    LedIndicatorCommandExecutor(CommandExecutor *commandExecutor);
    virtual ~LedIndicatorCommandExecutor(){};
    virtual void executeCommand(Command *command);
};

#endif /* LedIndicatorCommandExecutor_h */
