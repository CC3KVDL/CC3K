//
//  player.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "player.h"

#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string pc_type,int x, int y):Thing{pc_type.substr(0,1),x,y},onDH{false},gold{0},mKiller{false}{}

Player::createPlayer(string type){
  if (type == "d"){(need to delete?)
     this = new Drow();
  }else if(type == "v"){
     this = new Vampire();
  }else if(type == "t"){
     this = new Troll();
  }else if (type == "g"){
     this = new Goblin();
  }else if (type == "s"){
      this = new Shade();
  }
}

void setmKiller(){
  mKiller = true;
}


void Player::attack(Thing* t){
  t->hurt(this);
}

void Player::hurt(Enemy* e){
    
}
