//
//  LivingRoomLampOnCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "LivingRoomLampOnCommand.h"
#include "Pinout.h"
#include "Particle.h"
#include "AukeyCommandCodes.h"

LivingRoomLampOnCommand::LivingRoomLampOnCommand() {
    description = "Turn On the Living room lamp";
#if defined(SPARK)
    rcSwitch.enableTransmit(PIN_433_MHZ_TX);
#endif
}

void LivingRoomLampOnCommand::execute() {
#if defined(SPARK)
    rcSwitch.send(AUKEY_LIVING_ROOM_LAMP_ON_COMMAND_CODE, AUKEY_PROTOCOL_CODE);
#endif
}
