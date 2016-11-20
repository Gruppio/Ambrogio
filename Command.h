//
//  Command.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include <string.h>

class Command {
public:
    const char *description = NULL;
    
    Command(){};
    virtual ~Command(){};
    virtual void execute() = 0;
};

#endif /* Command_h */
