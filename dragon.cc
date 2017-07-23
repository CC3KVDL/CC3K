//
//  dragon.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include "dragon.h"

Dragon:: Dragon(int x, int y): Enemy{x, y, "Ddragon", 150, 20, 20}, hoard{nullptr} {}

Dragon:: ~Dragon() {}

void Dragon::setHoard(Thing* t) {
  hoard = t;
}

Thing* Dragon::getHoard() {
  return hoard;
}
