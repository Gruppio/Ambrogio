//
//  CommandFactory.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include <string.h>
#include "IP.h"
#include "CommandFactory.h"
#include "CommandsName.h"
#include "LedPanelOnCommand.h"
#include "LedPanelOffCommand.h"
#include "AukeyCommand.h"
#include "CompositeCommand.h"
#include "HttpGetCommand.h"
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
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_PANEL_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_PANEL_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LIVING_ROOM_LAMP_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LIVING_ROOM_LAMP_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LIVING_ROOM_LAMP_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LED_STRIP_LEFT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LED_STRIP_LEFT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_LEFT_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LED_STRIP_RIGHT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LED_STRIP_RIGHT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_LED_STRIP_RIGHT_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, COFFEE_MACHINE_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_COFFEE_MACHINE_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, COFFEE_MACHINE_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_COFFEE_MACHINE_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, CHRISTMAS_TREE_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_CHRISTMAS_TREE_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, CHRISTMAS_TREE_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_CHRISTMAS_TREE_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, FAN_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_FAN_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, FAN_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_FAN_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LIVINGROOM_LIGHT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new HttpGetCommand(LIGHT_LOCAL_IP_ADDRESS, "/toggle"), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, LIVINGROOM_LIGHT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new HttpGetCommand(LIGHT_LOCAL_IP_ADDRESS, "/toggle"), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, KITCHEN_LIGHT_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_KITCHEN_LIGHT_ON_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, KITCHEN_LIGHT_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, false, applianceStateRecorder);
        return new CompositeCommand({new AukeyCommand(remoteController, AUKEY_KITCHEN_LIGHT_OFF_COMMAND_CODE), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, MOON_ON) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new HttpGetCommand(MOON_LOCAL_IP_ADDRESS, "/on"), applianceStateRecorderCommand}, commandName);
    }

    if (strcmp(commandName, MOON_OFF) == 0) {
        Command *applianceStateRecorderCommand = new ApplianceStateRecorderCommand(applianceName, true, applianceStateRecorder);
        return new CompositeCommand({new HttpGetCommand(MOON_LOCAL_IP_ADDRESS, "/off"), applianceStateRecorderCommand}, commandName);
    }

    // Composite Commands

    if (strcmp(commandName, KITCHEN_LAMP_ON) == 0) {
        return createCommand(KITCHEN_LIGHT_ON);
    }

    if (strcmp(commandName, KITCHEN_LAMP_OFF) == 0) {
        return createCommand(KITCHEN_LIGHT_OFF);
    }

    if (strcmp(commandName, LED_STRIPS_ON) == 0) {
        return new CompositeCommand({createCommand(LED_STRIP_LEFT_ON), createCommand(LED_STRIP_RIGHT_ON)}, commandName);
    }

    if (strcmp(commandName, LED_STRIPS_OFF) == 0) {
        return new CompositeCommand({createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF)}, commandName);
    }

    if (strcmp(commandName, LIVINGROOM_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_ON), createCommand(LIVING_ROOM_LAMP_ON)}, commandName);
    }

    if (strcmp(commandName, LIVINGROOM_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_OFF), createCommand(LIVING_ROOM_LAMP_OFF)}, commandName);
    }

    if (strcmp(commandName, EATING_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LED_PANEL_ON), createCommand(KITCHEN_LIGHT_ON)}, commandName);
    }

    if (strcmp(commandName, EATING_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LED_PANEL_OFF), createCommand(KITCHEN_LIGHT_OFF)}, commandName);
    }

    if (strcmp(commandName, COOKING_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(KITCHEN_LIGHT_ON), createCommand(LED_STRIP_LEFT_ON), createCommand(LED_STRIP_RIGHT_ON)}, commandName);
    }

    if (strcmp(commandName, COOKING_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF)}, commandName);
    }

    if (strcmp(commandName, ALL_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_ON), createCommand(KITCHEN_LIGHT_ON), createCommand(LED_PANEL_ON), createCommand(LED_STRIP_LEFT_ON), createCommand(LED_STRIP_RIGHT_ON), createCommand(LIVING_ROOM_LAMP_ON)}, commandName);
    }

    if (strcmp(commandName, ALL_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_OFF)}, commandName);
    }

    if (strcmp(commandName, TV_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_ON)}, commandName);
    }

    if (strcmp(commandName, TV_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVING_ROOM_LAMP_OFF) }, commandName);
    }

    if (strcmp(commandName, OUT_LIGHTS_ON) == 0) {
        return new CompositeCommand({ createCommand(LIVINGROOM_LIGHT_OFF), createCommand(KITCHEN_LIGHT_OFF), createCommand(LED_PANEL_OFF), createCommand(LED_STRIP_LEFT_OFF), createCommand(LED_STRIP_RIGHT_OFF), createCommand(LIVING_ROOM_LAMP_ON)}, commandName);
    }

    if (strcmp(commandName, OUT_LIGHTS_OFF) == 0) {
        return new CompositeCommand({ createCommand(LIVING_ROOM_LAMP_OFF) }, commandName);
    }

    return new NullCommand();
}
