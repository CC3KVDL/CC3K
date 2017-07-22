//
//  floor.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include "floor.h"
#include "cell.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"

using namespace std;

// This
vector<string> cell_names = {"-", "|", "+", "#", "\\", " "};
vector<string> enemy_names = {"H", "W", "L", "E", "O", "M", "D"};

// what appears first are helper functions
// This is the implementation of getPos
int getPos(int& x, int& y) {
    srand(time(NULL));
    int v = rand()%5; // generate 0~4
    if (v == 0) {
        int v0 = rand()%104; // chambre1 -> 4 * 26 = 104 tiles 1~104
        int row = v0 / 26;
        int col = v0 % 26;
        x = row + 3;
        y = col + 3;
        
    } else if (v == 1) {
        int v1 = rand()%201; // chambre2 -> 201 tiles
        if ((v1 >= 0) && (v1 <= 45)) {
            x = v1 / 23 + 3;
            y = v1 % 23 + 39;
        } else if ((v1 >= 46) && (v1 <= 76)) {
            x = 5;
            y = v1 - 46 + 39;
        } else if ((v1 >= 77) && (v1 <= 110)) {
            x = 6;
            y = v1 - 77 + 39;
        } else {
            x = (v1 - 111) / 15 + 7;
            y = (v1 - 111) % 15 + 61;
        }
        
    } else if (v == 2) {
        int v2 = rand()%36; // chambre3 -> 36 tiles -> 3 * 12
        x = v2 / 12 + 10;
        y = v2 % 12 + 38;
        
    } else if (v == 3) {
        int v3 = rand()%147; // chambre4 -> 147 tiles -> 21 * 7
        x = v3 / 21 + 15;
        y = v3 % 21 + 4;
        
    } else {
        int v4 = rand()%150; // chanbre5 -> 150 tiles
        if ((v4 >= 0) && (v4 <= 32)) {
            x = v4 / 11 + 16;
            y = v4 % 11 + 65;
        } else {
            x = (v4 - 33) / 39 + 19;
            y = (v4 - 33) % 39 + 37;
        }
    }
    return v;
}

// This is the implementation of cmpEnemies
bool cmpEnemies(Enemy *a, Enemy *b) {
    if (a->getX() > b->getX()) {
        return true;
    } else if (a->getX() == b->getX()) {
        return a->getY() > b->getY();
    } else {
        return false;
    }
}


// ctor && dtor
Floor :: Floor(Display* dis): mes{"Action: "}, dis{dis} {
    grid.resize(25);
    for (int i = 0; i < 25; ++ i) {
        grid[i].resize(79);
    }
    for (int i = 0; i < 25; ++ i) {
        for (int j = 0; j < 79; ++ j) {
            grid[i][j] = nullptr;
        }
    }
}

Floor:: ~Floor() {
    for (int i = 0; i < 25; ++ i) {
        for (int j = 0; j < 79; ++ j) {
            if (grid[i][j]->getName()[0] == '@') {
                Thing *pc = grid[i][j];
                grid[i][j] = pc->getOn();
                pc->setOn(nullptr);
            }
            delete grid[i][j];
        }
    }
}


// initializing the floor
void Floor:: readMap(string filename,Player* pc) {
    ifstream file{filename};
    string line;
    string cell;
    vector<Thing *> DHs; // array of pointers to Dragon Hoard
    vector<Thing *> Ds; // array of pointers to Dragon
    for (int i = 0; i < 25; ++ i) {
        getline(file, line);
        for (int j = 0; j < 79; ++ j) {
            cell = line[i];
            if (cell == "9") {
                init(i, j, cell);
                DHs.push_back(grid[i][j]);
            }else if (cell == "D") {
                init(i, j, cell);
                Ds.push_back(grid[i][j]);
            }else if (cell=="@"){
                grid[i][j] = pc;
                pc->setX(i);
                pc->setY(j);
                dis->notify(pc);
            }else{
                init(i, j, cell);
            }
        }
    }
    
    // Set the owner of a Dragon Hoard to a specific Dragon and set the hoard of a Dragon to a specific Gold
    for (int i = 0 ; i < DHs.size();++i){
        int x = DHs[i]->getX();
        int y = DHs[i]->getY();
        for (int j = -1; j <= 1; ++j){
            for (int k = -1 ; k <= 1; ++k){
                Thing *D = grid[x+j][y+k]; // suppose it is a dragon
                if (D->getName() == "D") {
                    if (find(Ds.begin(), Ds.end(), D) != Ds.end()) {
                        DHs[i]->setOwner(D); // set Owner of gold
                        D->setHoard(DHs[i]); // set Gold of dragon
                        Ds.erase(remove(Ds.begin(), Ds.end(), D), Ds.end());
                    }
                }
            }
        }
    }
    
}


void Floor:: init(int x, int y, string c) {
    bool isCell = find(cell_names.begin(), cell_names.end(), c) != cell_names.end();
    bool isEnemy = find(enemy_names.begin(), enemy_names.end(), c) != enemy_names.end();
    
    // deleting the tile
    delete grid[x][y];
    
    // adding enemy
    if (isCell) {
        grid[x][y] = new Cell(c, x, y);
    } else if (isEnemy) {
        grid[x][y] = Enemy::createEnemy(c, x, y);
        Enemies.push_back(grid[x][y]);
    } else if (c == "0") {
        grid[x][y] = new Potion("PRH",x,y);
    } else if (c == "1") {
        grid[x][y] = new Potion("PBA",x,y);
    } else if (c == "2") {
        grid[x][y] = new Potion("PBD",x,y);
    } else if (c == "3") {
        grid[x][y] = new Potion("PPH",x,y);
    } else if (c == "4") {
        grid[x][y] = new Potion("PWA",x,y);
    } else if (c == "5") {
        grid[x][y] = new Potion("PWD",x,y);
    } else if (c == "6") {
        grid[x][y] = new Gold("GN",x,y); // normal gold
    } else if (c == "7") {
        grid[x][y] = new Gold("GS",x,y); // small gold
    } else if (c == "8") {
        grid[x][y] = new Gold("GH",x,y); // merchant gold
    } else if (c == "9") {
        grid[x][y] = new Gold("GD",x,y); // dragon gold
    }
    
    // notifying display
    dis->notify(grid[x][y]);
}

void Floor:: print(Player *pc, int f){
    dis->print();
    pc->printStatus(f);
    cout << mes << endl;
    mes = "Action: ";
}

// randomly generate things (This is called when no map has been provided)

bool Floor::checkNbs(int x, int y) { // a helper function to set gold
    bool result = false;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; i<=1; j++) {
            if (i!=0 || j!=0) {
                result = result || (grid[x+i][y+j]->getName() == ".");
            }
        }
    }
    return result;
}

void Floor::spawnEverything(Player *pc){
    // set player
    int x, y, chmbr;
    chmbr = getPos(x, y);
    pc->setOn(grid[x][y]);
    grid[x][y] = pc;
    
    // set stairway
    while (getPos(x, y) == chmbr){}
    init(x,y,"\\");
    
    // set potions
    for (int i=0; i < 10; i++) {
        srand(time(NULL));
        int p = rand()%6; // p is a random number from 0--5
        string pn = to_string(p);
        
        getPos(x, y);
        while (grid[x][y]->getName() != ".") {
            getPos(x, y);
        }
        init(x, y, pn);
    }
    
    // set golds
    for (int i=0; i < 10; i++) {
        srand(time(NULL));
        int g = rand()%8 + 1;
        string gn; // gold name
        if (g >= 1 && g <= 5) {
            gn = "6";
        } else if (g == 6 || g == 7) {
            gn = "7";
        } else {
            gn = "9";
        }
        
        getPos(x, y);
        // if the pos is not walkable or none of its neighbours are valid choose again
        while (grid[x][y]->getName() != "." || !checkNbs(x, y)) {
            getPos(x, y);
        }
        
        init(x, y, gn);
        
        // set the dragon
        if (gn == "9") {
            while (true) {
                int i = rand()%3 - 1;
                int j = rand()%3 - 1;
                if (grid[x+i][y+j]->getName() == ".") {
                    init(x+i, y+j, "D");
                    grid[x][y]->setOwner(grid[x+i][y+j]); // set Owner of gold
                    grid[x+i][y+j]->setHoard(grid[x][y]); // set Hoard of dragon
                    break;
                }
            }
        }
    }
    
    //set enemies
    for (int i=0; i<20; i++) {
        srand(time(NULL));
        int e = rand()%18 + 1;
        string en; // enemy name
        if (1<=e && e<=4) {
            en = "H";
        } else if (5<=e && e<=7) {
            en = "W";
        } else if (8<=e && e<=12) {
            en = "F";
        } else if (13==e || e==14) {
            en = "E";
        } else if (15==e || e==16) {
            en = "O";
        } else {
            en = "M";
        }
        
        getPos(x, y);
        while (grid[x][y]->getName() != ".") {
            getPos(x, y);
        }
        
        init(x, y, en); // we pushed enemy into Enemies in the function init!!
        
    }
}

void Floor:: movePlayer(Player* pc, string dir){
    int x_pc = pc->getX(); // where pc is at
    int y_pc = pc->getY();
    int x_new = x_pc; // where "I" want to go
    int y_new = y_pc;
    if (dir == "no") {
        x_new-=1;
    } else if (dir == "ne") {
        x_new-=1;
        y_new+=1;
    } else if (dir == "ea") {
        y_new+=1;
    } else if (dir == "se") {
        x_new+=1;
        y_new+=1;
    } else if (dir == "so") {
        x_new+=1;
    } else if (dir == "sw") {
        x_new+=1;
        y_new-=1;
    } else if (dir == "we") {
        y_new-=1;
    } else if (dir == "nw") {
        x_new-=1;
        y_new-=1;
    }
    
    // here is when pc actually walks
    Thing *whereTo = grid[x_new][y_new]; // Thing pc wants to step on
    vector<string> walkable = {"G", ".", "+", "#", "\\"}; // Names of Tings that can step on
    string whatTo = grid[x_new][y_new]->getName(); // Name of Thing pc want to step on
    if (find(walkable.begin(), walkable.end(), whatTo) != walkable.end()) {
        grid[x_pc][y_pc] = pc->getOn();
        pc->setOn(whereTo);
        grid[x_new][y_new] = pc;
        pc->setX(x_new);
        pc->setY(y_new);
        //update message
        mes = mes + "Player moves" + dir + ".";
    }
    
    // Now we "DON'T" let pc pick up a gold yet!!!
}

// pick up gold; enemies in radius attack pc; Dragon attack pc;
void Floor:: check(Player* pc) {
    Thing *sOn = pc->getOn(); // what "I" am standing on
    int x = pc->getX();
    int y = pc->getY();
    
    // pick up gold that I am on and change it to a tile
    if (sOn->getName()[0] == 'G' && sOn->getOwner() == nullptr){
        // pick it up
        pc->addGold(sOn->getValue());
        
        // update message
        mes += "PC picks up a gold of value " + to_string(sOn->getValue()) + " .";
        
        // set new tile
        delete pc->getOn();
        Thing *nOn = new Cell(".", x, y);
        pc->setOn(nOn);
    }
    
    // enemies in radius attack pc, dragon attack pc
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++){
            Thing *what = grid[x+i][y+j]; // This is the thing you see(may attack you)
            string name = what->getName().substr(0,1); // name
            bool isEnemy = find(enemy_names.begin(), enemy_names.end(), name) != enemy_names.end();
            bool isGold = name == "G";
            if (isEnemy) {
                mes += grid[x+i][y+j]->attack(*pc);
            } else if (isGold && what->getOwner() != nullptr) {
                mes += what->getOwner()->attack(*pc); // dragon attack pc
            }
        }
    }
}



// move all enemies randomly
void Floor:: moveEnemies() {
    // sort
    sort(Enemies.begin(), Enemies.end(), cmpEnemies);
    
    // move
    for (int i = 0; i < Enemies.size(); ++i) {
        while (!Enemies[i]->getStand()) {
            int v1 = rand()%3-1;
            int v2 = rand()%3-1;
            int x = Enemies[i]->getX();
            int y = Enemies[i]->getY();
            if (grid[v1+x][v2+y]->getName() == ".") {
                Enemies[i]->setX(v1+x);
                Enemies[i]->setY(v2+y);
                grid[v1+x][v2+y]->setX(x);
                grid[v1+x][v2+y]->setY(y);
                std::swap(grid[x][y], grid[v1+x][v2+y]);
                dis->notify(grid[x][y]);
                dis->notify(grid[v1+x][v2+y]);
                break;
            }
        }
        Enemies[i]->setStand();
    }
}


// what pc do

// attackEnemy should get gold from dead enemy and modify dragons
void Floor:: attackEnemy(Player *pc, string dir) {
    // enemy's direction
    int x = pc->getX();
    int y = pc->getY();
    if (dir == "no") {
        x-=1;
    } else if (dir == "ne") {
        x-=1;
        y+=1;
    } else if (dir == "ea") {
        y+=1;
    } else if (dir == "se") {
        x+=1;
        y+=1;
    } else if (dir == "so") {
        x+=1;
    } else if (dir == "sw") {
        x+=1;
        y-=1;
    } else if (dir == "we") {
        y-=1;
    } else if (dir == "nw") {
        x-=1;
        y-=1;
    }
    
    // if enemy, attack
    Thing *enemy = grid[x][y];
    string name = enemy->getName().substr(0,1);
    if (find(enemy_names.begin(), enemy_names.end(), name) != enemy_names.end()) {
         //update message
         mes += pc->attack(*enemy);
       
       
        // check if attacking a merchant
        if (name == "M") {
            pc->setmKiller();
        }
        
        // check if enemy is dead && pick up gold && delete it && make it to tile
        if (enemy->getHp() <= 0) {
            if (name == "H") {
                pc->addGold(4);
            } else if (name == "M") {
                pc->addGold(4);
            } else if (name == "D") {
                pc->addGold(0);
            } else {
                srand(time(NULL));
                int v = rand()%2+1; // 1~2
                pc->addGold(v);
            }
            init(x, y, ".");
            
            // delete killed enemy
            for (int i=0; i < Enemies.size(); i++) {
                if (Enemies[i]->getName() == ".") {
                    Enemies.erase(Enemies.begin() + i);
                    break;
                }
            }
            
            // if goblin, steals 5 gold
            if (pc->getName() == "@goblin") {
                pc->addGold(5);
            }
        }
    }
}
// NOTICE: don't move the enemy attacked!!!!!!!!

void Floor:: usePotion(Player *pc, string dir) {
    // potion's direction
    int x = pc->getX();
    int y = pc->getY();
    if (dir == "no") {
        x-=1;
    } else if (dir == "ne") {
        x-=1;
        y+=1;
    } else if (dir == "ea") {
        y+=1;
    } else if (dir == "se") {
        x+=1;
        y+=1;
    } else if (dir == "so") {
        x+=1;
    } else if (dir == "sw") {
        x+=1;
        y-=1;
    } else if (dir == "we") {
        y-=1;
    } else if (dir == "nw") {
        x-=1;
        y-=1;
    }
    
    if (grid[x][y]->getName()[0] == 'P') {
        //update message
        mes = mes + pc->use(grid[x][y]);
    }
    
    init(x, y, ".");
}
    



