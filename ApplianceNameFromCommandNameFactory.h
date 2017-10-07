//
//  ApplianceNameFromCommandFactory.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef ApplianceNameFromCommandFactory_h
#define ApplianceNameFromCommandFactory_h

#include <stdio.h>
#include "Command.h"


class ApplianceNameFromCommandNameFactory {
public:
    const char * getApplianceName(const char * commandName);
};

#endif /* ApplianceNameFromCommandFactory_h */
