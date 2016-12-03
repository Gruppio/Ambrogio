//
//  AukeyCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef AukeyCommand_h
#define AukeyCommand_h

#include "Command.h"
#include "Ambrogio.h"

class AukeyCommand: public Command {
protected:
    RCSwitch *rcSwitch;
    void transmitCode(unsigned long code);
    
public:
    AukeyCommand();
    virtual ~AukeyCommand();
    virtual void execute();
    
};

#endif /* AukeyCommand_h */
