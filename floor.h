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
    int height;
    int width;
    std::vector<std::vector<Thing*>> grid;
    std::vector<Enemy *> Enemies;
    std::string mes;
    Display *dis;

public:
    // ctor / dtor
    Floor(std::string fileName, Display* dis);
    ~Floor();
    
    
    void init(int x, int y, char c);
    void print(); // print out the current map
    void moveEnemy(); // move all enemies randomly
    void movePlayer(Player* pc, std::string dir); // move pc to a direction
    void randomGold(); // randomly create gold
    void randomPotion(); // randomly create potions
    void randomEnemy(); // randomly create enemies
    void check(); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;
    void attackEnemy(Player *pc, std::string dir);
    void usePotion(Player *pc, std::string dir);
    
};


#endif /* floor_h */
