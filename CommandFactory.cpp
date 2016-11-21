//
//  CommandFactory.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include <string.h>
#include "CommandFactory.h"
#include "CommandsName.h"
#include "LedPanelOnCommand.h"
#include "LedPanelOffCommand.h"
#include "LivingRoomLampOnCommand.h"
#include "LivingRoomLampOffCommand.h"

Command* CommandFactory::createCommand(const char* commandName) {
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        return new LedPanelOnCommand();
    }
    
    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        return new LedPanelOffCommand();
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_ON) == 0) {
        return new LivingRoomLampOnCommand();
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_OFF) == 0) {
        return new LivingRoomLampOffCommand();
    }
    
    return new NullCommand();
}
