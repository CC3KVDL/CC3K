//
//  player.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//


#include "player.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "shade.h"
#include <iostream>
#include <cmath>

using namespace std;

// ctor && dtor
Player::Player(std::string pc_type, int hp, int atk, int def): Thing{pc_type,0,0}, hp{hp}, atk{atk}, def{def}, gold{0}, On{shared_ptr<Thing>(nullptr)}, mKiller{false} {}
Player::~Player(){}

shared_ptr<Player> Player::createPlayer(string type){
    if (type == "d"){
        return shared_ptr<Drow>(new Drow());
    }else if(type == "v"){
        return shared_ptr<Vampire>(new Vampire());
    }else if(type == "t"){
        return shared_ptr<Troll>(new Troll());
    }else if (type == "g"){
        return shared_ptr<Goblin>(new Goblin());
    }else{
        return shared_ptr<Shade>(new Shade());
    }
}


string Player::attack(Thing &t){
    t.setStand(true) ;
    if (t.getName()=="Lhalfling"){
        int i = rand()%2;
        if (i == 0){
            return t.hurt(*this);
        } else {
            return "";
        }
    }else{
        return t.hurt(*this);
    }
}

string Player::hurt(Enemy &e){
    int hurt = ceil(100 *e.atk / (100 + def));
    addHp(-hurt);
    string m = e.getName().substr(1) + " deals " + to_string(hurt) + " to PC . ";
    return m;
}

string Player::use(shared_ptr<Thing> t){
    t->modify(this);
    string m = "PC uses " + t->getName().substr(1) + " . ";
    return m;
}




//modify relevant field;
void Player::addHp(int amount){
    hp = hp + amount;
    if (this->getName()=="@Drow" && hp > 150){
        hp = 150;
    }else if (this->getName() == "@Troll" && hp > 120){
        hp = 120;
    }else if (this->getName() == "@Shade" && hp > 120){
        hp = 120;
    }else if (this->getName() == "@Goblin" && hp > 110){
        hp = 110;
    }
    if (hp <= 0){
        hp = 0;
    }
}


void Player::addGold(int amount){
    gold = gold + amount;
}

void Player::addAtk(int amount){
    atk = atk + amount;
    if (atk < 0){
        atk = 0;
    }
}

void Player::addDef(int amount){
    def = def + amount;
    if (def < 0){
        def = 0;
    }
}




//accessor
Thing* Player::getOn(){
    return On;
}

bool Player::getmKiller(){
    return mKiller;
}

int Player:: getHp() {
    return hp;
}


int Player:: getGold() {
    return gold;
}



//mutator
void Player::setmKiller(){
    mKiller = true;
}

void Player::setOn(shared_ptr<Thing> t){
    On = t;
}

void Player::initStatus(){
    if (getName() == "@Vampire"){
        atk = 25;
        def = 25;
    }else if (getName() == "@Shade"){
        atk = 25;
        def = 25;
    }else if (getName() == "@Drow"){
        atk = 25;
        def = 15;
    }else if (getName() == "@Troll"){
        atk = 25;
        def = 15;
    }else if (getName() == "@Goblin"){
        atk = 15;
        def = 20;
    }
}


void Player::printStatus(int floor){
    cout << "Race: " << getName().substr(1) << " " << "Gold: " << gold << endl;
    for (int i = 0 ; i < 50; ++i){
        cout << " ";
    }
    cout << "Floor: " <<  floor << endl;
    cout << "HP: " << hp << endl;
    cout << "Atk: " << atk << endl;
    cout << "Def: " << def <<  endl;
}




