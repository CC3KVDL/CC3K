//
//  halfling.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef halfling_h
#define halfling_h

#include "enemy.h"

class Halfling: public Enemy {
public:
    Halfling(int x, int y);
    void attack(Player &p);
    void hurt(Player &p);
    ~Halfling();
};

#endif /* halfling_hpp */
