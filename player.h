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
#include <memory>
#include <cstdlib>
#include "thing.h"
#include "enemy.h"
#include "type.h"


class Player: public Thing{
protected:
    int hp;
    int atk;
    int def;
    int gold;
    std::shared_ptr<Thing> On; // Thing that the Player is stepping on
    bool mKiller; // True if "I" have killed merchant
    
public:
    
    // ctor && dtor
    Player(std::string pc_type, int hp, int atk, int def);
    virtual ~Player();
    
    // actions of player
    static std::shared_ptr<Player> createPlayer(std::string pc_type);
    virtual std::string attack(Thing &t) override;
    virtual std::string hurt(Enemy &e) override;
    std::string use(std::shared_ptr<Thing> t) override; // This is the first version, in DLC this should be a virtual

    //mutate relevant fields
    void addHp(int amount);
    void addAtk(int amount);
    void addDef(int amount);
    void addGold(int amount); // This is called whenever "I" steps on a pile of gold or "I" killed an enemy
    
    //accessor
    int getHp() override;
    int getGold();
    std::shared_ptr<Thing> getOn() override;
    bool getmKiller() override;
    
    //mutator
    void setOn(std::shared_ptr<Thing> t) override; // Let pc step on something
    void setmKiller();
    void initStatus();

    //printer
    void printStatus(int floor); // Print out the status of "me"
   
    friend class Enemy;
};


#endif /* player_h */
