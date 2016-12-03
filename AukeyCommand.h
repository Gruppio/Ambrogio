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
#include "RemoteController.h"
#include "Ambrogio.h"

class AukeyCommand: public Command {
protected:
    RemoteController *remoteController;
    REMOTE_CONTROLLER_TRANSMIT_TYPE code;
    
public:
    AukeyCommand(RemoteController *remoteController, REMOTE_CONTROLLER_TRANSMIT_TYPE code, const char *description);
    virtual ~AukeyCommand() {};
    virtual void execute();
    
};

#endif /* AukeyCommand_h */
