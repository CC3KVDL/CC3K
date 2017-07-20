//
//  enemy.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "enemy.h"
using namespace std;

Enemy * Enemy:: createEnemy(string name, int x, int y) {
  if (name == "H" ) {
    return new Human(x,y);
  } else if (name == "W") {
    return new Dwarf(x, y);
  } else if (name == "E") {
    return new Elf(x, y);
  } else if (name == "O") {
    return new Orcs(x, y);
  } else if (name == "M") {
    return new Merchant(x, y);
  } else if (name == "D") {
    return new Dragon(x, y);
  } else {
    return new Halfling(x, y);
  }
}

Enemy:: Enemy(int x, int y, std:: string name, int hp, int atk, int def): Thing{name, x, y}, hp{hp}, atk{atk}, def{def} {}

void Enemy:: attack(Player &p) {
  srand(time(NULL));
  int v = rand()%2; // 0~1
  if (v) {
   p.hurt(*this);
  }
}

void Enemy:: hurt(Player &p) {
  int hurt = (100 / (100 + def))*p.getAtk();
  hp -= hurt;
}

Enemy:: ~Enemy();


