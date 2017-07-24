//
//  elf.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <string>
#include "elf.h"
#include "player.h"

using namespace std;

Elf:: Elf(int x, int y): Enemy{x, y, "Eelf", 140, 30, 10} {}

string Elf:: attack(Thing &t){
    string mes;
    if (t.getName() == "@Drow") {
        int v = rand()%2; // generate 0~1
        if (v) {
            return t.hurt(*this);
        } else {
            return "";
        }
    } else {
        int v1 = rand()%2; // generate 0~1
        if (v1) {
            mes += t.hurt(*this);
        }
        int v2 = rand()%2; // generate 0~1
        if (v2) {
            mes += t.hurt(*this);
        }
        return mes;
    }
}

Elf:: ~Elf() {}

