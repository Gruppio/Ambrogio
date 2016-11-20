//
//  LedPanelOffCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LedPanelOffCommand_h
#define LedPanelOffCommand_h

#include "Command.h"

class LedPanelOffCommand: public Command {
public:
    LedPanelOffCommand();
    virtual ~LedPanelOffCommand(){};
    virtual void execute();
};

#endif /* LedPanelOnCommand_h */
