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

class Player;

class Enemy: public Thing {
protected:
    int hp;
    int atk;
    int def;
    bool stand;
public:

    // ctor && dtor
    Enemy(int x, int y, std::string name, int hp, int atk, int def);
    virtual ~Enemy();
    
    // actions of enemy
    virtual std:: string attack(Thing &t) override;
    std:: string hurt(Player &p) override;
    static std::shared_ptr<Enemy> createEnemy(std::string name, int x, int y);
    
    // accessor
    int getHp() override;
    int getAtk();
    bool getStand() override;
    
    
    // mutator
    void setStand(bool s) override;
    
    friend class Player;
};

#endif /* enemy_h */
