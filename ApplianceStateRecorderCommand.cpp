//
//  ApplianceStateRecorderCommandDecorator.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "ApplianceStateRecorderCommand.h"

ApplianceStateRecorderCommand::ApplianceStateRecorderCommand(const char * applianceName, bool state, ApplianceStateRecorder *stateRecorder) {
    this->applianceName = applianceName;
    this->state = state;
    this->stateRecorder = stateRecorder;
}

void ApplianceStateRecorderCommand::execute() {
    stateRecorder->setApplianceState(applianceName, state);
}

