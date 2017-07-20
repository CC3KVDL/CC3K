//
//  drow.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "drow.h"

using namespace std;

Drow::Drow(){
  hp = 150;
  atk = 25;
  def = 15;
}

void Drow::attack(Enemy &e);

void Drow::hurt(Enemy &e);

Drow::~Drow();
