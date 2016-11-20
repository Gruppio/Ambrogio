//
//  LedPanelOnCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LedPanelOnCommand_h
#define LedPanelOnCommand_h

#include "Command.h"

class LedPanelOnCommand: public Command {
public:
    LedPanelOnCommand();
    virtual ~LedPanelOnCommand(){};
    virtual void execute();
};

#endif /* LedPanelOnCommand_h */
