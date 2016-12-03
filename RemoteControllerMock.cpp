//
//  RemoteControllerMock.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "RemoteControllerMock.h"

void RemoteControllerMock::transmit(REMOTE_CONTROLLER_TRANSMIT_TYPE code) {
    this->codeSent = code;
}
