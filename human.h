//
//  human.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef human_h
#define human_h

#include "enemy.h"

class Human: public Enemy {
public:
    Human();
    void attack(Player &p);
    void hurt(Player &p);
    ~Human();
};

#endif /* human_h */
