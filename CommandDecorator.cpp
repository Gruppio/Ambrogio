//
//  CommandDecorator.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "CommandDecorator.h"

CommandDecorator::CommandDecorator(Command *command)
:command(command) {
}

void CommandDecorator::execute() {
    command->execute();
}

