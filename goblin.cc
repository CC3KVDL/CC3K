//
//  goblin.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "goblin.h"

Goblin::Goblin(): Player{"@goblin", 110, 15, 20}{}

    
void Goblin::hurt(Enemy &e) {
  int hurt = (100 / (100 + def))*e.getAtk();
  if (e->getName()=="Oorcs"){
    addHp(-hurt*1.5);
  }else{
    addHp(-hurt);
  }
}

Goblin::~Goblin(){}
