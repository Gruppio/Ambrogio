//
//  Command.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef Command_h
#define Command_h

class Command {
public:
    Command(){};
    virtual ~Command(){};
    virtual void execute() = 0;
};

#endif /* Command_h */
