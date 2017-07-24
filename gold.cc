//
//  gold.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <iostream>
#include <string>
#include "gold.h"

using namespace std;

Gold:: Gold(string name, int x, int y, shared_ptr<Thing> owner): Thing{name, x, y}, owner{owner} {
    if (name == "GD") { // dragon gold
        value = 8;
    } else if (name == "GS") { // small gold
        value = 1;
    } else if (name == "GN") { // normal gold
        value = 2;
    } else if (name == "GH") { //merchant gold
        value = 4;
    }
}

void Gold:: setOwner(shared_ptr<Thing> t) {
    owner = t;
}

shared_ptr<Thing> Gold:: getOwner() {
    return owner;
}

int Gold:: getValue() {
    return value;
}

Gold:: ~Gold() {}

