//
//  goblin.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "goblin.h"
using namespace std;

Goblin::Goblin(): Player{"@goblin", 110, 15, 20}{}

    
string Goblin::hurt(Enemy &e) {
  int hurt = (100 / (100 + def))* e.getAtk();
  string m;
  if (e.getName()=="Oorcs"){
    addHp(-hurt*1.5);
    m = m + e.getName.substr(1) +  " deals " + to_string(hurt) + " damage to PC . ";
  }else{
    addHp(-hurt);
    m = m + e.getName.substr(1) +  " deals " + to_string(hurt) + " damage to PC . ";
  }
    return m;
}

Goblin::~Goblin(){}
