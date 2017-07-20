//
//  goblin.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef goblin_h
#define goblin_h

#include "player.h"
#include "thing.h"

class Goblin: public Player {
public:
    Goblin();
    void hurt(Enemy &e) override;
    ~Goblin();
};

#endif /* goblin_h */
