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
  if (p.getName() == "@drow") {
    p.hurt(*this);
  } else {
    p.hurt(*this);
    p.hurt(*this);
  }
}
