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
#include "display.h"
#include "player.h"

class Display;
class Player;

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
    virtual void attack(Thing* t);
    virtual void use(Thing * t);

    // Virtual Method for Gold
    virtual void setOwner(Thing *t);
    virtual int getValue();
    Thing *getOwner();
    
    // Virtual Method for Potion
    virtual void modify(Player *pc);
};

#endif /* thing_h */
