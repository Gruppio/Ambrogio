//
//  ParticleEventCommandExecutor.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef ParticleEventCommandExecutor_h
#define ParticleEventCommandExecutor_h

#include "CommandExecutorDecorator.h"

class ParticleEventCommandExecutor: public CommandExecutorDecorator {
public:
    ParticleEventCommandExecutor(CommandExecutor *commandExecutor);
    virtual ~ParticleEventCommandExecutor(){};
    virtual void executeCommand(Command *command);
};

#endif /* ParticleEventCommandExecutor_h */
