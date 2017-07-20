//
//  troll.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "troll.h"


Troll::Troll(){
  hp = 120;
  atk = 25;
  def = 15;
}
    
void Troll::attack(Enemy &e);
    
void Troll::hurt(Enemy &e);
    
Troll::~Troll();
