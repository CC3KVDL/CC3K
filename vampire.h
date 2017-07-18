//
//  vampire.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef vampire_h
#define vampire_h

#include "player.h"
#include "thing.h"

class Vampire: public Player {
public:
    Vampire();
    void attack(Enemy &e);
    void hurt(Enemy &e);
    ~Vampire();
};

#endif /* vampire_h */
