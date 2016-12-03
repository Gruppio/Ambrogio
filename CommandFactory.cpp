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
#include "AukeyCommand.h"

CommandFactory::CommandFactory(RemoteController *remoteController) {
    this->remoteController = remoteController;
}

Command* CommandFactory::createCommand(const char* commandName) {
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        return new LedPanelOnCommand();
    }
    
    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        return new LedPanelOffCommand();
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_ON) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_ON_COMMAND_CODE, "Turn on the living room lamp");
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_OFF) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_OFF_COMMAND_CODE, "Turn off the living room lamp");
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_ON) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_ON_COMMAND_CODE, "Turn on the kitchen left led strip");
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_OFF) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_OFF_COMMAND_CODE, "Turn off the kitchen left led strip");
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_ON) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_ON_COMMAND_CODE, "Turn on the kitchen right led strip");
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_OFF) == 0) {
        return new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_OFF_COMMAND_CODE, "Turn off the kitchen right led strip");
    }
    
    return new NullCommand();
}
