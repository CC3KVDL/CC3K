//
//  elf.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "elf.h"
#include "player.h"

Elf:: Elf(int x, int y): Enemy{x, y, "Eelf", 140, 30, 10} {}

std:: string Elf:: attack(Player &p){
  if (p.getName() == "@drow") {
  int v = rand()%2; // generate 0~1
    if (v) {
    return p.hurt(*this);
    } else {
      return "";
    }
  } else {
    int v1 = rand()%2; // generate 0~1 
    if (v1) {
    return p.hurt(*this);
    } else {
      return "";
    }
    int v2 = rand()%2; // generate 0~1
    if (v2) {
    return p.hurt(*this);
    } else {
      return "";
    }
  }
}

Elf:: ~Elf() {}
