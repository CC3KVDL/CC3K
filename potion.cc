//
//  potion.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "potion.h"

using namespace std;

Potion::Potion(string name,int x, int y):Thing{name, x, y}{
  if (name == "PRH"){
    hp = 10;
    atk = 0;
    def = 0;
  }else if (name == "PBA"){
    atk = 5;
    hp = 0;
    def = 0;
  }else if (name == "PBD"){
    def = 5;
    hp = 0;
    atk = 0;
  }else if (name == "PPH"){
    hp = -10;
    def = 0;
    atk = 0;
  }else if (name  == "PWA"){
    atk = -5;
    hp = 0;
    def = 0;
  }else if (name == "PWD"){
    def = -5;
    atk = 0;
    hp = 0;
  } 
}

void Potion::modify(Player* p){
  if (p->getName()=="@drow"){
    p->addHp(hp*1.5);                               //magfinied
    p->addAtk(atk*1.5);
    p->addDef(def*1.5);
 }else{
    p->addHp(hp);
    p->addAtk(atk);
    p->addDef(def);
 }
}
