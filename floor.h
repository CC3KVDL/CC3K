//
//  floor.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef floor_h
#define floor_h

#include "thing.h"
#include "enemy.h"
#include <vector>

class Floor {
    int height = 25;
    int width = 79;
    std::vector<std::vector<Thing>> grid;// Needs to be deleted !!
    std::vector<Enemy *> Enemies;
    std::string mes;
    Display *dis;

public:
    // ctor / dtor
    Floor(std::string fileName);
    ~Floor();
    
    
    void init(int x, int y, char c);
    void print();
    void moveEnemy();
    void movePlayer(Player* pc, std::string dir);
    void randomGold(); // randomly create glod
    void randomPotion(); // ... potion
    void randomEnemy(); // ... enemy
    void check(); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;
    void attackEnemy(Player *pc, std::string dir);
    void usePotion(Player *pc, std::string dir);
    
};


#endif /* floor_h */
