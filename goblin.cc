//
//  goblin.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "goblin.h"

Goblin::Goblin(){
  hp = 110;
  atk = 15;
  def = 20;
}

    
void Goblin::hurt(Enemy &e) override{
  int hurt = (100 / (100 + def))*e.getAtk();
  if (e->getName()=="Oorcs"){
    addHp(-hurt*1.5);
  }else{
    addHp(-hurt);
  }
}

Goblin::~Goblin(){}
