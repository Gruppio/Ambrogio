//
//  NullCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef NullCommand_h
#define NullCommand_h

#include "Command.h"

class NullCommand: public Command {
public:
    NullCommand();
    virtual ~NullCommand(){};
    virtual void execute();
};

#endif /* NullCommand_h */
