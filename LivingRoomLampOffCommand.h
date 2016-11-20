//
//  LivingRoomLampOffCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LivingRoomLampOffCommand_h
#define LivingRoomLampOffCommand_h

#include "Command.h"

#if defined(SPARK)
#include "RCSwitch.h"
#endif

class LivingRoomLampOffCommand: public Command {
private:
#if defined(SPARK)
    RCSwitch rcSwitch = RCSwitch();
#endif
    
public:
    LivingRoomLampOffCommand();
    virtual ~LivingRoomLampOffCommand(){};
    virtual void execute();
};

#endif /* LivingRoomLampOffCommand_h */
