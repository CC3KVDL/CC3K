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
    Dragon(int x, int y);
    ~Dragon();
};

#endif /* dragon_h */
