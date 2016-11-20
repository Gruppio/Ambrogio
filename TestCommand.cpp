//
//  TestCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "TestCommand.h"

TestCommand::TestCommand() {
    description = "Test Command";
}

void TestCommand::execute() {
    numberOfExecutions++;
}
