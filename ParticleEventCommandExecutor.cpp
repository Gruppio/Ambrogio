//
//  ParticleEventCommandExecutor.cpp
//  Ambrogio
//
//  Created by Gruppioni Michele on 03/12/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#include "ParticleEventCommandExecutor.h"
#include "Particle.h"

ParticleEventCommandExecutor::ParticleEventCommandExecutor(CommandExecutor *commandExecutor)
: CommandExecutorDecorator(commandExecutor) {
}

void ParticleEventCommandExecutor::executeCommand(Command *command) {
#if defined(SPARK)
    Particle.publish("command", String::format("%s", command->description), PRIVATE);
#endif
    commandExecutor->executeCommand(command);
}
