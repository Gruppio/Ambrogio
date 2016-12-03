//
//  RemoteController.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef RemoteController_h
#define RemoteController_h

#define REMOTE_CONTROLLER_TRANSMIT_TYPE unsigned long

class RemoteController {
public:
    RemoteController() {};
    virtual ~RemoteController() {};
    virtual void transmit(REMOTE_CONTROLLER_TRANSMIT_TYPE) = 0;
};


#endif /* RemoteController_h */
