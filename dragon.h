//
//  dragon.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef dragon_h
#define dragon_h

#include "enemy.h"

class Dragon: public Enemy {
public:
    Dragon();
    void attack(Player &p);
    void hurt(Player &p);
    ~Dragon();
};

#endif /* dragon_h */