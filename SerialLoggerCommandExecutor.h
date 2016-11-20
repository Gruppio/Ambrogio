//
//  SerialLoggerCommandExecutor.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef SerialLoggerCommandExecutor_h
#define SerialLoggerCommandExecutor_h

#include "CommandExecutorDecorator.h"

class SerialLoggerCommandExecutor: public CommandExecutorDecorator {
public:
    SerialLoggerCommandExecutor(CommandExecutor *commandExecutor);
    virtual ~SerialLoggerCommandExecutor(){};
    virtual void executeCommand(Command *command);
};

#endif /* SerialLoggerCommandExecutor_h */
