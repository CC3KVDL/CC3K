//
//  player.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef player_h
#define player_h
#include <string>
#include "thing.h"
#include "enemy.h"

class Player: public Thing{
    int hp;
    int atk;
    int def;
    int gold;
    Thing* On; // Thing that the Player is stepping on
    bool mKiller; // True if "I" have killed merchant
public:
    Player(std::string pc_type = "", int x=-1, int y=-1, Thing* On);
    virtual ~Player();
    Player *createPlayer(std::string pc_type);
    virtual void attack(Enemy &e);
    virtual void hurt(Enemy &e);
    
    void gainGold(int amount); // This is called whenever "I" steps on a pile of gold or "I" killed an enemy
    void getOn();
    void getGold();
    void getHp();
    
    void setOn(Thing* t);
    
    void printStatus(); // Print out the status of "me"
    void use(Thing *t); // This is the first version, in DLC this should be a virtual
    friend class Enemy;
};


#endif /* player_h */
