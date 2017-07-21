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
#include "display.h"
#include <vector>

// getPos(x, y) is a function to randomly generate a position in any chambre and returns
// which chambre it was hte position is in (0--4)
int getPos(int &x, int &y);

// isIn(ele, arr) checks if a certain element(a string) is in the array and returns a boolean
bool isIn(std::string ele, std::vector<std::string>);

// sortEnemies is a function to compare to enemies and decide their sequence.
bool cmpEnemies(Enemy *a, Enemy *b);

class Floor {
    std::vector<std::vector<Thing *>> grid; // the real grid of objects
    std::vector<Enemy *> Enemies; // an array of enemies
    std::string mes; // the message that you print out each time
    Display *dis; // a field to keep track of the display

public:
    // ctor / dtor
    Floor(Display* dis);
    ~Floor();
    
    // initializing the floor and printing
    void readMap(std::string filename = "default.txt", Player *pc = nullptr);
    void init(int x, int y, std::string c); // initial a signle Thing
    void print(); // print out the current map
    void spawnEverything(Player *pc);
    std:: string getMes();
    
    // what pc do
    void movePlayer(Player* pc, std::string dir); // move pc to a direction
    void attackEnemy(Player *pc, std::string dir);
    void usePotion(Player *pc, std::string dir);
    void check(Player *pc); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;
    void moveEnemies(); // move all enemies randomly
    
};


#endif /* floor_h */
