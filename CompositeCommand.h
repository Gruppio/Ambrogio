//
//  CompositeCommand.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef CompositeCommand_h
#define CompositeCommand_h

#include "Command.h"
#include <vector>

class CompositeCommand: public Command {
protected:
    const char *description;
    std::vector<Command*> commands;
    
public:
    CompositeCommand(std::vector<Command*> commands, const char *description = "");
    virtual ~CompositeCommand();
    virtual void execute();
    //virtual const char * getDescription();
};

#endif /* CompositeCommand_h */
