//
//  Particle.h
//  Ambrogio
//
//  Created by Gruppioni Michele on 20/11/2016.
//  Copyright © 2016 Michele Gruppioni. All rights reserved.
//

#ifndef Particle_h
#define Particle_h

#if defined(SPARK)
#include "application.h"
#else
#define delay(x)
#define pinMode(x, y)
#define digitalWrite(x, y)
#define INPUT
#define OUTPUT
#define HIGH
#endif

#endif /* Particle_h */
