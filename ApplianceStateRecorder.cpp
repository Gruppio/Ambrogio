//
//  ApplianceStateRecorder.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "ApplianceStateRecorder.h"

void ApplianceStateRecorder::setApplianceState(const char * applianceName, bool state) {
    appliancesState[applianceName] = state;
}

bool ApplianceStateRecorder::getApplianceState(const char * applianceName) {
    return appliancesState[applianceName];
}
