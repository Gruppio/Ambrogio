//
//  CommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "CommandExecutor.hpp"

void CommandExecutor::executeCommand(Command *command) {
    command->execute();
}
