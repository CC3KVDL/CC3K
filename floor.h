//
//  floor.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef floor_h
#define floor_h

#include "thing.h"
#include <vector>

class Floor {
    int height = 25;
    int width = 79;
    std::vector<std::vector<Thing>> grid; // Needs to be deleted !!
public:
    void init();
    void print();
};


#endif /* floor_h */
