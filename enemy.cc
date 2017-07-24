//
//  enemy.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <sstream>
#include <cmath>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "elf.h"
#include "halfling.h"
using namespace std;

// ctor && dtor
Enemy:: Enemy(int x, int y, std:: string name, int hp, int atk, int def): Thing{name, x, y}, hp{hp}, atk{atk}, def{def}, stand{false} {}
Enemy:: ~Enemy() {}

// actions of enemy
shared_ptr<Enemy> Enemy:: createEnemy(string name, int x, int y) {
    if (name == "H" ) {
        return shared_ptr<Human>(new Human(x,y));
    } else if (name == "W") {
        return shared_ptr<Dwarf>(new Dwarf(x, y));
    } else if (name == "E") {
        return shared_ptr<Elf>(new Elf(x, y));
    } else if (name == "O") {
        return shared_ptr<Orcs>(new Orcs(x, y));
    } else if (name == "M") {
        return shared_ptr<Merchant>(new Merchant(x, y));
    } else if (name == "D") {
        return shared_ptr<Dragon>(new Dragon(x, y));
    } else {
        return shared_ptr<Halfling>(new Halfling(x, y));
    }
}
string Enemy:: attack(Thing &t) {
    int v = rand()%2; // 0~1
    if (v) {
        return t.hurt(*this);
    } else {
        return "";
    }
}
string Enemy:: hurt(Player &p) {
    int hurt = ceil(100 *p.atk/ (100 + def));
    hp -= hurt;
    if (hp < 0) { hp = 0; }
    string name_p = p.getName().substr(1);
    string name_e = getName().substr(1);
    string damage = to_string(hurt);
    string hp_e = to_string(hp);
    string mes = name_p + " " + "deals " + damage + " to " + name_e + "( " + hp_e + " )" + ". ";
    return mes;
}

void Enemy::setHoard(shared_ptr<Thing> t) {}


shared_ptr<Thing> Enemy::getHoard() {return nullptr;}


// accessor
int Enemy::getHp() {
    return hp;
}
int Enemy::getAtk() {
    return atk;
}

bool Enemy:: getStand() {
    return stand;
}

// mutator
void Enemy:: setStand(bool s) {
    stand = s;
}






