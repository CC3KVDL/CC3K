//
//  thing.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "thing.h"
using namespace std;

// Method all "thing" can call
Thing::Thing(string name, int x, int y):name{name},x{x}, y{y}{}
int Thing::getX(){return x;}
int Thing::getY(){return y;}
string Thing::getName(){
    return name;
}

Thing::~Thing(){}

//Virtual Method for Player and Enemy
void Thing::attack(Thing* t){}
void Thing::use(Thing* t){}

// Virtual Method for Gold
void Thing::setOwner(Thing* t){}
int Thing::getValue(){
    return -1;
}
Thing* Thing::getOwner(){}

// Virtual Method for Potion
void Thing::modify(Player *pc) {}

