//
//  CommandFactory.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "CommandFactory.h"
#include "LedPanelOnCommand.h"
#include "LedPanelOffCommand.h"
#include "CommandsName.h"

Command* CommandFactory::createCommand(const char* commandName) {
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        return new LedPanelOnCommand();
    }
    
    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        return new LedPanelOffCommand();
    }
    
    return new NullCommand();
}
