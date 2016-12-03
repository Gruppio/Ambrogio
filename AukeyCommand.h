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
#if defined(SPARK)
#include "RCSwitch.h"
#endif

class AukeyCommand: public Command {
protected:
#if defined(SPARK)
    RCSwitch *rcSwitch;
#endif
    void transmitCode(int code);
    
public:
    AukeyCommand();
    virtual ~AukeyCommand();
    virtual void execute();
    
};

#endif /* AukeyCommand_h */
