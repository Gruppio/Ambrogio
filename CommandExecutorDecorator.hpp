//
//  CommandExecutorDecorator.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandExecutorDecorator_hpp
#define CommandExecutorDecorator_hpp

#include "CommandExecutor.hpp"

class CommandExecutorDecorator: public CommandExecutor {
protected:
    CommandExecutor *commandExecutor;
public:
    
    
};

#endif /* CommandExecutorDecorator_hpp */
