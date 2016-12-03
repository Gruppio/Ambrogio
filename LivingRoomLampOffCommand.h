//
//  LivingRoomLampOffCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LivingRoomLampOffCommand_h
#define LivingRoomLampOffCommand_h

#include "AukeyCommand.h"

class LivingRoomLampOffCommand: public AukeyCommand {    
public:
    LivingRoomLampOffCommand();
    virtual ~LivingRoomLampOffCommand(){};
    virtual void execute();
};

#endif /* LivingRoomLampOffCommand_h */
