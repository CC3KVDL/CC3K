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
bool cmpEnemies(std::shared_ptr<Thing> a, std::shared_ptr<Thing> b);

class Floor {
    std::vector<std::vector<std::shared_ptr<Thing>>> grid; // the real grid of objects
    std::vector<std::shared_ptr<Thing>> Enemies; // an array of enemies
    std::string mes; // the message that you print out each time
    std::shared_ptr<Display> dis; // a field to keep track of the display

public:
    // ctor / dtor
    Floor(std::shared_ptr<Display> dis);
    ~Floor();
    
    // initializing the floor and printing
    void readMap(std::shared_ptr<Player> pc, std::string filename = "default.txt");
    void init(int x, int y, std::string c); // initial a signle Thing
    void print(std::shared_ptr<Player> pc, int f); // print out the current map
    bool checkNbs(int x, int y); //check if one of the neighbours is spawnable
    void spawnEverything(std::shared_ptr<Player> pc);
    
    // what pc do
    void movePlayer(std::shared_ptr<Player> pc, std::string dir); // move pc to a direction
    void attackEnemy(std::shared_ptr<Player> pc, std::string dir);
    void usePotion(std::shared_ptr<Player> pc, std::string dir);
    void check(std::shared_ptr<Player> pc); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;
    void moveEnemies(); // move all enemies randomly
    void freePlayer(std::shared_ptr<Thing> pc); // take pc off the grid
    
};


#endif /* floor_h */
