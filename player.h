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
#include <cstdlib>
#include "thing.h"

class Player: public Thing{
    int hp;
    int atk;
    int def;
    int gold;
    Thing* On; // Thing that the Player is stepping on
    bool mKiller; // True if "I" have killed merchant
public:
    Player(std::string pc_type, int hp, int atk, int def);
    virtual ~Player();
    static Player *createPlayer(std::string pc_type);
    virtual void attack(Thing& e);
    virtual void hurt(Enemy &e);
    void use(Thing *t); // This is the first version, in DLC this should be a virtual
    
    //mutate relevant fields
    void addHp(int amount);
    void addAtk(int amout);
    void addDef(int amout);
    void addGold(int amount); // This is called whenever "I" steps on a pile of gold or "I" killed an enemy
    
    //accessor
    Thing *getOn();
    int getGold();
    int getHp();
    bool getmKiller();
    
    //mutator
    void setOn(Thing* t); // Let pc step on something
    void setmKiller();
    void initStatus();

    
    
    void printStatus(); // Print out the status of "me"
   
    friend class Enemy;
};


#endif /* player_h */
