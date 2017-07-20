//
//  enemy.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef enemy_h
#define enemy_h
#include "thing.h"
#include "player.h"

class Player;

class Enemy: public Thing {
    int hp;
    int atk;
    int def;
public:
    Enemy(int x, int y, std::string name, int hp, int atk, int def);
    virtual void attack(Player &p);
    virtual void hurt(Player &p);
    static Enemy *createEnemy(std::string name, int x, int y);
    virtual ~Enemy();
};

#endif /* enemy_h */
