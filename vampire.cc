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

void Vampire::attack(Enemy &e){
  if (r->getName()=="Wdwarf"){
    hp = hp - 5;
  }else{
    hp = hp + 5;
  }
  //default attack;
}



void hurt(Enemy &e){}
Vampire::~Vampire(){}
