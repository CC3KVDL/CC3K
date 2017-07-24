//
//  potion.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef potion_h
#define potion_h

#include "thing.h"
#include "player.h"

class Potion : public Thing {
    int hp;
    int atk;
    int def;
public:
    Potion(std::string name, int x, int y);
    void modify(Player& p);
    ~Potion();
};


#endif /* potion_h */
