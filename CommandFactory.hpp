//
//  CommandFactory.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef CommandFactory_hpp
#define CommandFactory_hpp

#include <string.h>
#include "Command.hpp"

class CommandFactory {
public:
    Command* createCommand(char* commandName);
};



#endif /* CommandFactory_hpp */
