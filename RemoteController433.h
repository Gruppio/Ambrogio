//
//  RemoteController433.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef RemoteController433_h
#define RemoteController433_h

#include "RemoteController.h"
#include "Ambrogio.h"

class RemoteController433: public RemoteController {
protected:
    RCSwitch *rcSwitch;
    
public:
    RemoteController433(RCSwitch *rcSwitch);
    virtual ~RemoteController433() {};
    virtual void transmit(REMOTE_CONTROLLER_TRANSMIT_TYPE code);
};

#endif /* RemoteController433_h */
