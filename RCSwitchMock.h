//
//  RCSwitchMock.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#if !defined(SPARK)
#ifndef RCSwitchMock_h
#define RCSwitchMock_h

#include <stdio.h>

class RCSwitch {
public:
    RCSwitch();
    void enableTransmit(int nTransmitterPin);
    void disableTransmit();
    void send(unsigned long code, unsigned int length);
};

#endif /* RCSwitchMock_h */
#endif
