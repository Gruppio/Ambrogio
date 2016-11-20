//
//  main.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 19/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#if defined(SPARK)
#else

#include <iostream>
#include "Command.h"
#include "CommandExecutor.h"
#include "CommandFactory.h"

void commandExecutorTests();

int main(int argc, const char * argv[]) {
    std::cout << "Start Tests\n";
    
    commandExecutorTests();
    
    std::cout << "Done\n\n";
    return 0;
}

void commandExecutorTests() {
    
}

#endif
