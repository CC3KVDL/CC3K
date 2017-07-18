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

Player::createPlayer(std::string type){
  if (type == "@drow"){(need to delete?)
     this = new Drow();
  }else if(type == "@vampire"){
     this = new Vampire();
  }else if(type == "@troll"){
     this = new Troll();
  }else if (type == "@goblin"){
     this = new Goblin();
  }else if (type == "@shade"){
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
