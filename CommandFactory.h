//
//  CommandFactory.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandFactory_h
#define CommandFactory_h

#include "Command.h"
#include "NullCommand.h"
#include "RemoteController.h"
#include "ApplianceStateRecorder.h"
#include "ApplianceNameFromCommandNameFactory.h"

class CommandFactory {
public:
    RemoteController *remoteController;
    ApplianceStateRecorder *applianceStateRecorder;
    ApplianceNameFromCommandNameFactory *applianceNameFactory;
    CommandFactory(RemoteController *remoteController, ApplianceStateRecorder *applianceStateRecorder, ApplianceNameFromCommandNameFactory *applianceNameFactory);
    Command* createCommand(const char* commandName);
};

#endif /* CommandFactory_h */
