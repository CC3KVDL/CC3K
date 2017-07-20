//
//  merchant.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "merchant.h"
#include <cstdlib>

Merchant:: Merchant(int x, int y): Enemy{x, y, "Mmerchant", 30, 70, 5} {}

void Merchant:: attack(Player &p) {
  if (p.getmKiller()) {
    srand(time(NULL));
    int v = rand()%2; // 0~1
    if (v) {
      p.hurt(*this);
    }
  }
}

Merchant:: ~Merchant() {}
