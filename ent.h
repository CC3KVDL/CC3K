//
//  ent.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-24.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef ent_hpp
#define ent_hpp

#include "enemy.h"

class Ent: public Enemy {
public:
    Ent(int x, int y);
    ~Ent();
};

#endif /* ent_hpp */
