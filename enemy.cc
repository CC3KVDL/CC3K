//
//  enemy.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <cstdlib>
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
Enemy:: Enemy(int x, int y, std:: string name, int hp, int atk, int def): Thing{name, x, y}, hp{hp}, atk{atk}, def{def} {}
Enemy:: ~Enemy() {}

// actions of enemy
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
void Enemy:: attack(Player &p) {
    srand(time(NULL));
    int v = rand()%2; // 0~1
    if (v) {
        p.hurt(*this);
    } else {
        p.setDamage(0);
    }
}
void Enemy:: hurt(Player &p) {
    int hurt = (100 / (100 + def))* p.atk;
    hp -= hurt;
    p.setDamage(hurt);
}

// accessor
int Enemy::getHp() {
    return hp;
}
int Enemy::getAtk() {
    return atk;
}
int Enemy:: getDamage() {
    return damage;
}




