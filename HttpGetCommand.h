//
//  HttpGetCommand.hpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 24/10/2017.
//  Copyright © 2017 Michele Gruppioni. All rights reserved.
//

#ifndef HttpGetCommand_hpp
#define HttpGetCommand_hpp

#include "Command.h"
#include "HttpClient.h"
#include "Ambrogio.h"

class HttpGetCommand: public Command {
protected:
    const char *hostname;
    const char *path;
    
public:
    HttpGetCommand(const char *hostname, const char *path, const char *description = "");
    virtual ~HttpGetCommand() {};
    virtual void execute();
};


#endif /* HttpGetCommand_hpp */
