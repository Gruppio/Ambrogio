//
//  CommandExecutor.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandExecutor_hpp
#define CommandExecutor_hpp

#include <stdio.h>
#include "Command.hpp"

class CommandExecutor {
public:
    virtual void executeCommand(Command *command);
};


#endif /* CommandExecutor_hpp */
