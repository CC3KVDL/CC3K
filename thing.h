//
//  thing.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef thing_h
#define thing_h
#include <memory>
#include <string>

class Player;
class Enemy;

class Thing {
    std::string name;
    int x;
    int y;
public:
    
    // Method all "thing" can call
    Thing(std::string name, int x=-1, int y=-1);
    int getX();
    int getY();
    void setX(int pos_x);
    void setY(int pos_y);
    std::string getName();
    virtual ~Thing();
    
    // Virtual Method for Player and Enemy
    virtual std::string attack(Thing &t);
    virtual int getHp();
    
    // Virtual Method only for Player
    virtual std::string use(Thing * t);
    virtual std::string hurt(Enemy &e);
    virtual Thing* getOn();
    virtual void setOn(Thing *t);
    virtual bool getmKiller();
    
    // Virtual Method only for Enemy
    virtual std::string hurt(Player &p);
    virtual void setStand(bool s);
    virtual bool getStand();
    virtual void setHoard(Thing* t);
    shared_ptr<Thing> getHoard();

    // Virtual Method for Gold
    virtual void setOwner(Thing *t);
    virtual int getValue();
    shared_ptr<Thing> getOwner();
    
    // Virtual Method for Potion
    virtual void modify(Player *pc);
};

#endif /* thing_h */
