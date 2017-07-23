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
shared_ptr<Thing> Thing::getOn(){return shared_ptr<Thing>(nullptr);}
void Thing::setOn(shared_ptr<Thing> t){}
bool Thing::getmKiller(){return false;}

// Virtual Methods for Enemy only
string Thing::hurt(Player &p) {return "";}
bool Thing::getStand(){return false;}
void Thing::setStand(bool s) {}
void Thing::setHoard(shared_ptr<Thing> t) {}
shared_ptr<Thing> Thing::getHoard(){return shared_ptr<Thing>(nullptr);}

// Virtual Method for Gold
void Thing::setOwner(shared_ptr<Thing> t){}
int Thing::getValue(){return -1;}
shared_ptr<Thing> Thing::getOwner(){return shared_ptr<Thing>(nullptr);}

// Virtual Method for Potion
void Thing::modify(shared_ptr<Player> pc) {}

