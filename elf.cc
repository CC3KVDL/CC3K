//
//  elf.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "elf.h"

Elf:: Elf(int x, int y): Enemy{x, y, "Eelf", 140, 30, 10} {}

void Elf:: attack(Player &p) override {
  srand(time(NULL));
  if (p.getName() == "@drow") {
  int v = rand()%2; // generate 0~1
    if (v) {
    p.hurt(*this);
    }
  } else {
    int v1 = rand()%2; // generate 0~1 
    if (v1) {
    p.hurt(*this);
    }
    int v2 = rand()%2; // generate 0~1
    if (v2) {
    p.hurt(*this);
    }
  }
}

Elf:: ~Elf() {}
