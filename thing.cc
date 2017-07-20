//
//  thing.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "thing.h"
using namespace std;

Thing::Thing(string name, int x, int y):name{name},x{x}, y{y}{}

int Thing::getX(){return x;}

int Thing::getY(){return y;}

string getName(){
  return name; 
}

Thing::~Thing(){}

void attack(Thing* t){}
void hurt(Thing* t){}
void use(Thing* t){}

void setOwner(Thing* t){}
int getValue(Thing* t){}
Thing* getOwner(){}

