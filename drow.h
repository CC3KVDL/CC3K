//
//  drow.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef drow_h
#define drow_h

#include "player.h"
#include "thing.h"

class Drow: public Player {
public:
    Drow();
    void attack(Enemy &e);
    void hurt(Enemy &e);
    ~Drow();
};

#endif /* drow_h */
