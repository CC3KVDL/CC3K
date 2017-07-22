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
    virtual std::string hurt(Thing &t);
    virtual std::string use(Thing * t);
    virtual int getHp();

    // Virtual Method for Gold
    virtual void setOwner(Thing *t);
    virtual int getValue();
    Thing *getOwner();
    
    // Virtual Method for Potion
    virtual void modify(Player *pc);
};

#endif /* thing_h */
