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
#include "CompositeCommand.h"
#include "ApplianceStateRecorderCommand.h"

CommandFactory::CommandFactory(RemoteController *remoteController, ApplianceStateRecorder *applianceStateRecorder, ApplianceNameFromCommandNameFactory *applianceNameFactory) {
    this->remoteController = remoteController;
    this->applianceStateRecorder = applianceStateRecorder;
    this->applianceNameFactory = applianceNameFactory;
}

Command* CommandFactory::createCommand(const char* commandName) {
    const char *applianceName = applianceNameFactory->getApplianceName(commandName); 
    
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new LedPanelOnCommand(), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new LedPanelOffCommand(), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_ON_COMMAND_CODE, "Turned on the living room lamp"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_OFF_COMMAND_CODE, "Turned off the living room lamp"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_ON_COMMAND_CODE, "Turned on the kitchen left led strip"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_OFF_COMMAND_CODE, "Turned off the kitchen left led strip"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_ON_COMMAND_CODE, "Turned on the kitchen right led strip"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_OFF_COMMAND_CODE, "Turned off the kitchen right led strip"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, COFFEE_MACHINE_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_COFFEE_MACHINE_ON_COMMAND_CODE, "Turned on the coffee machine"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, COFFEE_MACHINE_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_COFFEE_MACHINE_OFF_COMMAND_CODE, "Turned off the coffee machine"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, CHRISTMAS_TREE_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_CHRISTMAS_TREE_ON_COMMAND_CODE, "Turned on the christmas tree"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, CHRISTMAS_TREE_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_CHRISTMAS_TREE_OFF_COMMAND_CODE, "Turned off the christmas tree"), applianceStateRecorderCommand});
    }
    
    return new NullCommand();
}
