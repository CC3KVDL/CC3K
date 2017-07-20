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
    
void Goblin::attack(Enemy &e);
    
void Goblin::hurt(Enemy &e);
   
Goblin::~Goblin();
