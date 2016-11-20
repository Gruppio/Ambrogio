//
//  TestCommand.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef TestCommand_hpp
#define TestCommand_hpp

#include "Command.hpp"

class TestCommand: public Command {
public:
    int numberOfExecutions = 0;
    virtual void execute();
};

#endif /* TestCommand_hpp */
