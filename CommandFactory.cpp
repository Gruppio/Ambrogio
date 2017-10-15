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
    
    if (strcmp(commandName, FAN_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_FAN_ON_COMMAND_CODE, "Turned on the fan"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, FAN_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_FAN_OFF_COMMAND_CODE, "Turned off the fan"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_1_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_1_ON_COMMAND_CODE, "Turned on livingroom light #1"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_1_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_1_OFF_COMMAND_CODE, "Turned off livingroom light #1"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_2_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_2_ON_COMMAND_CODE, "Turned on livingroom light #2"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_2_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_2_OFF_COMMAND_CODE, "Turned off livingroom light #2"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_3_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_1_ON_COMMAND_CODE, "Turned on livingroom light #3"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_3_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVINGROOM_LIGHT_1_OFF_COMMAND_CODE, "Turned off livingroom light #3"), applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, MOON_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new NullCommand() , applianceStateRecorderCommand});
    }
    
    if (strcmp(commandName, MOON_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new NullCommand() , applianceStateRecorderCommand});
    }
    
    // Composite Commands
        
    if (strcmp(commandName, LIVINGROOM_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_ON), createCommand(LIVINGROOM_LIGHT_2_ON), createCommand(LIVINGROOM_LIGHT_3_ON)});
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_OFF), createCommand(LIVINGROOM_LIGHT_2_OFF), createCommand(LIVINGROOM_LIGHT_3_OFF)});
    }
    
    if (strcmp(commandName, EATING_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LED_PANEL_ON), createCommand(KITCHEN_LIGHT_ON)});
    }
    
    if (strcmp(commandName, EATING_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LED_PANEL_OFF), createCommand(KITCHEN_LIGHT_OFF)});
    }
    
    if (strcmp(commandName, COOKING_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(KITCHEN_LIGHT_ON), createCommand(LED_STRIP_LEFT_ON), createCommand(LED_STRIP_RIGHT_ON)});
    }
    
    if (strcmp(commandName, COOKING_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF)});
    }
    
    if (strcmp(commandName, ALL_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_ON), createCommand(LIVINGROOM_LIGHT_2_ON), createCommand(LIVINGROOM_LIGHT_3_ON), createCommand(KITCHEN_LIGHT_ON), createCommand(LED_PANEL_ON), createCommand(LED_STRIP_LEFT_ON), createCommand(LED_STRIP_RIGHT_ON), createCommand(LIVING_ROOM_LAMP_ON)});
    }
    
    if (strcmp(commandName, ALL_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_OFF), createCommand(LIVINGROOM_LIGHT_2_OFF), createCommand(LIVINGROOM_LIGHT_3_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_OFF)});
    }
    
    if (strcmp(commandName, TV_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_OFF), createCommand(LIVINGROOM_LIGHT_2_OFF), createCommand(LIVINGROOM_LIGHT_3_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_ON)});
    }
    
    if (strcmp(commandName, TV_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVING_ROOM_LAMP_OFF) });
    }
    
    if (strcmp(commandName, OUT_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_1_OFF), createCommand(LIVINGROOM_LIGHT_2_OFF), createCommand(LIVINGROOM_LIGHT_3_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_ON)});
    }
    
    if (strcmp(commandName, OUT_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVING_ROOM_LAMP_OFF) });
    }
    
    return new NullCommand();
}
