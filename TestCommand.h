//
//  TestCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifdef TEST

#ifndef TestCommand_h
#define TestCommand_h

#include "Command.h"

class TestCommand: public Command {
public:
    int numberOfExecutions = 0;
    
    TestCommand();
    virtual ~TestCommand(){};
    virtual void execute();
};

#endif /* TestCommand_h */

#endif
