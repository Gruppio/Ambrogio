//
//  ApplianceStateRecorderCommandDecorator.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef ApplianceStateRecorderCommand_h
#define ApplianceStateRecorderCommand_h

#include "Command.h"
#include "ApplianceStateRecorder.h"


class ApplianceStateRecorderCommand: public Command {
protected:
    const char * applianceName;
    bool state;
    ApplianceStateRecorder *stateRecorder;

public:
    ApplianceStateRecorderCommand(const char * applianceName, bool state, ApplianceStateRecorder *stateRecorder);
    virtual ~ApplianceStateRecorderCommand(){};
    virtual void execute();
};

#endif /* ApplianceStateRecorderCommand_h */
