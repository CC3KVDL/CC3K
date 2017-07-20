//
//  dwarf.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef dwarf_h
#define dwarf_h

#include "enemy.h"

class Dwarf: public Enemy {
public:
    Dwarf(int x, int y);
    void hurt(Player &p);
    ~Dwarf();
};

#endif /* dwarf_h */
