//
//  CommandExecutor.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandExecutor_h
#define CommandExecutor_h

#include <stdio.h>
#include "Command.h"

class CommandExecutor {
public:
    virtual void executeCommand(Command *command);
};


#endif /* CommandExecutor_h */
