//
//  player.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//


#include "player.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "shade.h"
#include <iostream>

using namespace std;

Player::Player(string pc_type,int x, int y, Thing* On):Thing{pc_type,x,y},gold{0},mKiller{false},On{On}{}

Player *Player::createPlayer(string type){
    if (type == "d"){
        return new Drow();
    }else if(type == "v"){
        return new Vampire();
    }else if(type == "t"){
        return new Troll();
    }else if (type == "g"){
        return new Goblin();
    }else if (type == "s"){
        return new Shade();
    }
}

bool Player::getmKiller(){
    return mKillier;
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

int Player::getHp(){
  return hp;
}

void Player::addHp(int amount){
  hp = hp + amount;
  if (this->getName()=="@human" && hp > 140){
      hp = 140;
  }else if (this->getName()=="@drow" && hp > 150){
     hp = 100;
  }else if (this->getName() == "@troll" && hp > 120){
     hp = 140;
  }else if (this->getName() == "@shade" && hp > 125){
    hp = 125;
  }else if (this->getName() == "@goblin" && hp > 110){
    hp = 110;
  }
  if (hp <= 0){
    hp = 0;
  }
}


void Player::addGold(int amount){
  gold = gold + amount;
}

void Player::addAtk(int amount){
    atk = atk + amount;
}

void Player::addDef(int amount){
    def = def + amount;
}

int Player::getGold(){
  return gold;
}

void Player::attack(Thing &e){
    if (e.getName()=="Lhalfling"){
      srand(time(NULL));
      int i = rand()%2;
      if (i == 0){
        e.hurt(*this);
      }
    }else{
        r.hurt(*this);
    }
}

Thing* Player::getOn(){
  return On;
}

void Player::use(Thing* t){
    t->modify(this);
}

void Player::hurt(Enemy &e){
  int hurt = (100 / (100 + def))*e.getAtk();
  addHp(-hurt);
}

Player::~Player(){}
