//
//  LivingRoomLampOnCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LivingRoomLampOnCommand.h"
#include "Ambrogio.h"

LivingRoomLampOnCommand::LivingRoomLampOnCommand() {
    description = "Turn On the Living room lamp";
}

void LivingRoomLampOnCommand::execute() {
    transmitCode(AUKEY_LIVING_ROOM_LAMP_ON_COMMAND_CODE);
}
