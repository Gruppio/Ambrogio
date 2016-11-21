//
//  CommandFactory.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandFactory_h
#define CommandFactory_h

#include "Command.h"
#include "NullCommand.h"

class CommandFactory {
public:
    CommandFactory(){};
    virtual ~CommandFactory(){};
    Command* createCommand(const char* commandName);
};

#endif /* CommandFactory_h */
