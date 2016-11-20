//
//  CommandFactory.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "CommandFactory.h"
#include "LedPanelOnCommand.h"

#define LED_PANEL_ON "LedPanelOn"

Command* CommandFactory::createCommand(char* commandName) {
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        return new LedPanelOnCommand();
    }
    
    return new NullCommand();
}
