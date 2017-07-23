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
void Thing::setX(int pos_x) {x = pos_x;}
void Thing::setY(int pos_y) {y = pos_y;}
string Thing::getName(){return name;}
Thing::~Thing(){}

//Virtual Method for Player and Enemy
string Thing::attack(Thing &t){return "";}
int Thing::getHp() {return 0;}


// Virtual Methods for Player only
string Thing::use(Thing* t){return "";}
string Thing::hurt(Enemy &e){return "";}
Thing* Thing::getOn(){return nullptr;}
void Thing::setOn(Thing *t){}
bool Thing::getmKiller(){return false;}

// Virtual Methods for Enemy only
string Thing::hurt(Player &p) {return "";}
bool Thing::getStand(){return false;}
void Thing::setStand(bool s) {}
void Thing::setHoard(Thing *t) {}
Thing* Thing::getHoard(){return nullptr;}

// Virtual Method for Gold
void Thing::setOwner(Thing* t){}
int Thing::getValue(){return -1;}
Thing* Thing::getOwner(){return nullptr;}

// Virtual Method for Potion
void Thing::modify(Player *pc) {}

