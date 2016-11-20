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
#if defined(SPARK)
    rcSwitch.enableTransmit(PIN_433_MHZ_TX);
#endif
}

void LivingRoomLampOffCommand::execute() {
#if defined(SPARK)
    rcSwitch.send(AUKEY_LIVING_ROOM_LAMP_OFF_COMMAND_CODE, AUKEY_PROTOCOL_CODE);
#endif
}
