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
    Thing* hoard;
    
public:
    Dragon(int x, int y);
    ~Dragon();
    void setHoard(Thing* t);
};

#endif /* dragon_h */
