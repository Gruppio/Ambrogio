//
//  TestCommand.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifdef TEST

#include "TestCommand.h"

TestCommand::TestCommand() {
    this->description = "Test Command";
}

void TestCommand::execute() {
    numberOfExecutions++;
}

#endif
