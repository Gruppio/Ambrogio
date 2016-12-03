//
//  RemoteControllerMock.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef RemoteControllerMock_h
#define RemoteControllerMock_h

#include "RemoteController.h"
#include "Ambrogio.h"

class RemoteControllerMock: public RemoteController {
public:
    REMOTE_CONTROLLER_TRANSMIT_TYPE codeSent;
    RemoteControllerMock() {};
    virtual ~RemoteControllerMock() {};
    virtual void transmit(REMOTE_CONTROLLER_TRANSMIT_TYPE code);
};

#endif /* RemoteControllerMock_h */
