//
//  ApplianceNameFromCommandFactory.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include <string.h>
#include "ApplianceNameFromCommandNameFactory.h"
#include "AppliancesNames.h"
#include "CommandsName.h"

const char * ApplianceNameFromCommandNameFactory::getApplianceName(const char * commandName) {
    if (strcmp(commandName, LED_PANEL_ON) == 0) {
        return LED_PANEL;
    }
    
    if (strcmp(commandName, LED_PANEL_OFF) == 0) {
        return LED_PANEL;
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_ON) == 0) {
        return LIVING_ROOM_LAMP;
    }
    
    if (strcmp(commandName, LIVING_ROOM_LAMP_OFF) == 0) {
        return LIVING_ROOM_LAMP;
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_ON) == 0) {
        return LED_STRIP_LEFT;
    }
    
    if (strcmp(commandName, LED_STRIP_LEFT_OFF) == 0) {
        return LED_STRIP_LEFT;
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_ON) == 0) {
        return LED_STRIP_RIGHT;
    }
    
    if (strcmp(commandName, LED_STRIP_RIGHT_OFF) == 0) {
        return LED_STRIP_RIGHT;
    }
    
    if (strcmp(commandName, COFFEE_MACHINE_ON) == 0) {
        return COFFEE_MACHINE;
    }
    
    if (strcmp(commandName, COFFEE_MACHINE_OFF) == 0) {
        return  COFFEE_MACHINE;
    }
    
    if (strcmp(commandName, CHRISTMAS_TREE_ON) == 0) {
        return CHRISTMAS_TREE;
    }
    
    if (strcmp(commandName, CHRISTMAS_TREE_OFF) == 0) {
        return FAN;
    }
    
    if (strcmp(commandName, FAN_ON) == 0) {
        return FAN;
    }
    
    if (strcmp(commandName, FAN_OFF) == 0) {
        return CHRISTMAS_TREE;
    }
    
    if (strcmp(commandName, KITCHEN_LIGHT_ON) == 0) {
        return KITCHEN_LIGHT;
    }
    
    if (strcmp(commandName, KITCHEN_LIGHT_OFF) == 0) {
        return KITCHEN_LIGHT;
    }
        
    if (strcmp(commandName, LIVINGROOM_LIGHT_1_ON) == 0) {
        return LIVINGROOM_LIGHT_1;
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_1_OFF) == 0) {
        return LIVINGROOM_LIGHT_1;
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_2_ON) == 0) {
        return LIVINGROOM_LIGHT_2;
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_2_OFF) == 0) {
        return LIVINGROOM_LIGHT_2;
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_3_ON) == 0) {
        return LIVINGROOM_LIGHT_3;
    }
    
    if (strcmp(commandName, LIVINGROOM_LIGHT_3_OFF) == 0) {
        return LIVINGROOM_LIGHT_3;
    }
    
    if (strcmp(commandName, MOON_ON) == 0) {
        return MOON;
    }
    
    if (strcmp(commandName, MOON_OFF) == 0) {
        return MOON;
    }
    
    if (strcmp(commandName, UNKNOWN_COMMAND) == 0) {
        return UNKNOWN_APPLIANCE;
    }
    
    return UNKNOWN_COMMAND;
}
