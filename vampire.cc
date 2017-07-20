//
//  vampire.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "vampire.h"

Vampire::Vampire(){
  hp = 50;
  atk = 25;
  def = 25;
}

void Vampire::attack(Enemy &e) override{
  if (e->getName()=="Wdwarf"){
    addHp(-5);
  }else{
    addHp(5);
  }
  //default attack
  e.hurt(*this);
}



Vampire::~Vampire(){}
