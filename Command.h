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
protected:
    const char *description;
public:
    Command(){};
    virtual ~Command(){};
    virtual void execute() = 0;
    virtual const char * getDescription();
};

#endif /* Command_h */
