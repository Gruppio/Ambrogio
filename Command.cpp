//
//  Command.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "Command.h"

Command::Command(const char *description) {
    this->description = description;
}

const char * Command::getDescription() {
    return description;
}
