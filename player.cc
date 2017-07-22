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

// ctor && dtor
Player::Player(std::string pc_type, int hp, int atk, int def): Thing{pc_type,0,0}, hp{hp}, atk{atk}, def{def}, gold{0}, On{nullptr}, mKiller{false} {}
Player::~Player(){}

Player *Player::createPlayer(string type){
    if (type == "d"){
        return new Drow();
    }else if(type == "v"){
        return new Vampire();
    }else if(type == "t"){
        return new Troll();
    }else if (type == "g"){
        return new Goblin();
    }else{
        return new Shade();
    }
}


string Player::attack(Thing &e){
    e.stand = true;
    if (e.getName()=="Lhalfling"){
      srand(time(NULL));
      int i = rand()%2;
      if (i == 0){
        return e.hurt(*this);
      }
    }else{
        return e.hurt(*this);
    }
}

string Player::hurt(Enemy &e){
  int hurt = (100 / (100 + def))*e.atk;
  addHp(-hurt);
  string m = e.getName().substr(1) + " deals " + to_string(hurt) + " to PC . ";
  return m;
}

string Player::use(Thing* t){
    t->modify(this);
    string m = "PC uses " + t.getName() + " . ";
    return m; 
}




//modify relevant field;
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
    if (atk < 0){
        atk = 0;
    }   
}

void Player::addDef(int amount){
    def = def + amount;
    if (def < 0){
       def = 0;
    }
}




//accessor
Thing* Player::getOn(){
  return On;
}

bool Player::getmKiller(){
    return mKiller;
}

int Player:: getHp() {
    return hp;
}


int Player:: getGold() {
    return gold;
}



//mutator
void Player::setmKiller(){
    mKiller = true;
}

void Player::setOn(Thing* t){
  On = t;
}

void Player::initStatus(){
  if (getName() == "@vampire"){
      atk = 25;
      def = 25;
  }else if (getName() == "@shade"){
      atk = 25;
      def = 25;
  }else if (getName() == "@drow"){
      atk = 25;
      def = 15;
  }else if (getName() == "@troll"){
      atk = 25;
      def = 15;
  }else if (getName() == "@goblin"){
      atk = 15;
      def = 20;
  }
}


void Player::printStatus(int floor){
  cout << "Race: " <<, name.substr(1) << " " << "Gold: " << gold << endl;
  for (int i = 0 ; i < 50; ++i){
      cout << " ";
  }
  cout << "Floor: " <<  floor << endl;
  cout << "HP: " << hp << endl;
  cout << "Atk: " << atk << endl;
  cout << "Def: " << def <<  endl;
}




