//
//  potion.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "potion.h"

Potion::Potion(string name,int x, int y):Thing{name, x, y}{
  if (name == "PRH"){
    hp = 10;
  }else if (name == "PBA"){
    atk = 5;
  }else if (name == "PBD"){
    def = 5;
  }else if (name == "PPH"){
    hp = -10;
  }else if (name  == "PWA"){
    atk = -5;
  }else if (name == "PWD"){
    def = -5;
  } 
}

Potion::modify(Player* p){
  if p->name=="@drow"{
    p.addhp(health*1.5);                               //magfinied
    p.addatk(atk*1.5);
    p.adddef(def*1.5);
 }else{
    p.addhp(health);
    p.addatk(atk);
    p.addddef(def);
 }
}
