//
//  troll.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef troll_h
#define troll_h

#include "player.h"
#include "thing.h"

class Troll: public Player {
public:
    Troll();
    void attack(Enemy &e);
    void hurt(Enemy &e);
    ~Troll();
};

#endif /* troll_h */
