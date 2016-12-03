//
//  RemoteController433.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "RemoteController433.h"

RemoteController433::RemoteController433(RCSwitch *rcSwitch) {
    rcSwitch = rcSwitch;
}

void RemoteController433::transmit(REMOTE_CONTROLLER_TRANSMIT_TYPE code) {
    rcSwitch->send(code, AUKEY_PROTOCOL_CODE);
}
