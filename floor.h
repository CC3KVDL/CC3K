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

// getPos is a function to randomly generate a position in any chambre and returns
// which chambre it was hte position is in (0--4)

int getPos(int &x, int &y);

class Floor {
    std::vector<std::vector<Thing *>> grid; // the real grid of objects
    std::vector<Enemy *> Enemies; // an array of enemies
    std::string mes; // the message that you print out each time
    Display *dis; // a field to keep track of the display

public:
    // ctor / dtor
    Floor(Display* dis);
    ~Floor();
    
    // initializing the floor
    void readMap(std::string filename = "default.txt");
    void init(int x, int y, char c);
    void print(); // print out the current map
    std:: string getMes();
    
    void moveEnemies(); // move all enemies randomly
    void movePlayer(Player* pc, std::string dir); // move pc to a direction
    void check(); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;
    
    
    // randomly generate things
    void spawnEverything(Player *pc); //
    void randomPlayer(Player* pc); // randomly put player somewhere
    void randomStair(); //
    void randomGold(); // randomly create gold
    void randomPotion(); // randomly create potions
    void randomEnemy(); // randomly create enemies
    
    void attackEnemy(Player *pc, std::string dir);
    void usePotion(Player *pc, std::string dir);
    
};


#endif /* floor_h */
