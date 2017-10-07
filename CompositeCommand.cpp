//
//  CompositeCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 07/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#include "CompositeCommand.h"

CompositeCommand::CompositeCommand(std::vector<Command*> commands)
:commands(commands) {
}

void CompositeCommand::execute() {
    for(Command * command : commands) {
        command->execute();
    }
}
