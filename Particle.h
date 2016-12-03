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
    #define log(message) Serial.println(message);
#else
    #include <iostream>
    #define log(message) std::cout << message << std::endl;

    #define delay(x)
    #define pinMode(x, y)
    #define digitalWrite(x, y)
    #define INPUT
    #define OUTPUT
    #define HIGH

    #define D0 0
    #define D1 1
    #define D2 2
    #define D3 3
    #define D4 4
    #define D5 5
    #define D6 6
    #define D7 7
    #define A0 8
    #define A1 9
    #define A2 10
    #define A3 11
    #define A4 12
    #define A5 13
    #define A6 14
    #define A7 15
#endif
#endif /* Particle_h */
