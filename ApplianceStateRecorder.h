//
//  ApplianceStateRecorder.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef ApplianceStateRecorder_h
#define ApplianceStateRecorder_h

#include <stdio.h>
#include <map>
#include <string>
#include <iterator>

class ApplianceStateRecorder {
public:
    std::map<std::string, bool> appliancesState;
    void setApplianceState(const char * applianceName, bool state);
    bool getApplianceState(const char * applianceName);
};

#endif /* ApplianceStateRecorder_h */
