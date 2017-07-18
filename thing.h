//
//  thing.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef thing_h
#define thing_h
#include <memory>
#include <string>
#include "display.h"

class Display;

class Thing {
    std::string name;
    int x;
    int y;
    std::unique_ptr<Display> display;
public:
    Thing(char name, int x, int y, bool attackable);
    void printName();
    char getName();
    virtual ~Thing();
};

#endif /* thing_h */
