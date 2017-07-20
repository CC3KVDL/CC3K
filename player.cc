//
//  player.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//


#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string pc_type,int x, int y, Thing* On):Thing{pc_type.substr(0,1),x,y},gold{0},mKiller{false},On{On}{}

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

void Player::setmKiller(){
  mKiller = true;
}

void Player::setOn(Thing* t){
  On = t;
}

void Player::printStatus(){
  cout << "HP: " << hp << endl;
  cout << "Atk: " << atk << endl;
  cout << "Def: " << def <<  endl;
}

void Player::getHp(){
  return hp;
}

void addHp(int value){
  hp = hp + value;
  if (name=="@human" && hp > 140){
      hp = 140;
  }else if (name=="@drow" && hp > 150){
     hp = 100;
  }else if (name == "@troll" && hp > 120){
     hp = 140;
  }else if (name == "@shade" && hp > 125){
    hp = 125;
  }else if (name == "@goblin" && hp > 110){
    hp = 110;
  }
  if (hp <= 0){
    hp = 0;
  }
}


void Player::gainGold(int amount){
  gold = gold + amount;
}

int Player::getGold(){
  return gold;
}

void Player::attack(Thing* t){
  t->hurt(this);
}

Thing* Player::getOn(){
  return On;
}

void Player::hurt(Enemy* e){
    
}

Player::~Player(){]
