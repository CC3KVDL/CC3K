//
//  vampire.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "vampire.h"

Vampire::Vampire(): Player{"@vampire", 50, 25, 25}{}

void Vampire::attack(Thing &e) {
  if (e.getName()=="Wdwarf"){
    addHp(-5);
  }else{
    addHp(5);
  }
  //default attack
  e.hurt(*this);
}



Vampire::~Vampire(){}
