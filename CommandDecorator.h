//
//  CommandDecorator.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef CommandDecorator_h
#define CommandDecorator_h

#include "Command.h"

class CommandDecorator: public Command {
protected:
    Command *command;
    
public:
    CommandDecorator(Command *command);
    virtual ~CommandDecorator(){};
    virtual void execute();
    //virtual const char * getDescription();
};

#endif /* CommandDecorator_h */
