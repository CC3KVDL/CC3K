//
//  display.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef display_h
#define display_h

#include "thing.h"

class Thing;

class Display {
    char map[25][79];
public:
    Display();
    void notify(std::shared_ptr<Thing> t);
    void print();
    ~Display();
};

#endif /* display_h */
