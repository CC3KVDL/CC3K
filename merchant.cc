//
//  merchant.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "merchant.h"
#include "player.h"
#include <cstdlib>

using namespace std;

Merchant:: Merchant(int x, int y): Enemy{x, y, "Mmerchant", 30, 70, 5} {}

string Merchant:: attack(Thing& t) {
  if (t.getmKiller()) {
    int v = rand()%2; // 0~1
    if (v) {
      return t.hurt(*this);
    } else {
      return "";
    }
  }else{
      return "";
  }
}

Merchant:: ~Merchant() {}
