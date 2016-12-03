//
//  LivingRoomLampOnCommand.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 21/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef LivingRoomLampOnCommand_h
#define LivingRoomLampOnCommand_h

#include "AukeyCommand.h"

class LivingRoomLampOnCommand: public AukeyCommand {
public:
    LivingRoomLampOnCommand();
    virtual ~LivingRoomLampOnCommand(){};
    virtual void execute();
};

#endif /* LivingRoomLampOnCommand_h */
