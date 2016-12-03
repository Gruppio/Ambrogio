//
//  LivingRoomLampOffCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LivingRoomLampOffCommand.h"
#include "Pinout.h"
#include "Particle.h"
#include "AukeyCommandCodes.h"

LivingRoomLampOffCommand::LivingRoomLampOffCommand() {
    description = "Turn Off the Living room lamp";
}

void LivingRoomLampOffCommand::execute() {
    transmitCode(AUKEY_LIVING_ROOM_LAMP_OFF_COMMAND_CODE);
}
