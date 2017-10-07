//
//  CompositeCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "CompositeCommand.h"
#include <string.h>
#include <string>

CompositeCommand::CompositeCommand(std::vector<Command*> commands)
:commands(commands) {
}

CompositeCommand::~CompositeCommand() {
    for(Command * command : commands) {
        delete command;
    }
}

void CompositeCommand::execute() {
    for(Command * command : commands) {
        command->execute();
    }
}

const char * CompositeCommand::getDescription() {
    std::string fullDescription = "";
    for(Command * command : commands) {
        const char * desc = command->getDescription();
        if (strlen(desc) > 2) {
            fullDescription += desc;
        }
    }
    return fullDescription.c_str();
}
