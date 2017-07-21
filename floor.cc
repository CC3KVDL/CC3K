//
//  floor.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "floor.h"
#include "cell.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"

using namespace std;

// This
vector<string> cell_names = {"-", "|", "+", "#", "\\", " "};
vector<string> enemy_names = {"M", "L", "D", "E", "L", "D", "H", "O"};

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
            delete grid[i][j];
        }
    }
    for (int i = 0; i < Enemies.size(); ++ i) {
        delete Enemies[i];
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
    
    // Set the owner of a Dragon Hoard to a specific Dragon
    for (int i = 0 ; i < DHs.size();++i){
        int x = DHs[i]->getX();
        int y = DHs[i]->getY();
        for (int j = -1; j <= 1; ++j){
            for (int k = -1 ; k <= 1; ++k){
                Thing *D = grid[x+j][y+k]; // suppose it is a dragon
                if (D->getName() == "D") {
                    if (find(Ds.begin(), Ds.end(), D) != Ds.end()) {
                        DHs[i]->setOwner(D);
                        Ds.erase(remove(Ds.begin(), Ds.end(), D), Ds.end());
                    }
                }
            }
        }
    }
    
}


void Floor:: init(int x, int y, string c) {
    vector<string> cell_names = {"-", "|", "+", "#", "\\", " ", "."};
    vector<string> enemy_names = {"M", "W", "L", "D", "E","H", "O"};
    bool isCell = find(cell_names.begin(), cell_names.end(), c) != cell_names.end();
    bool isEnemy = find(enemy_names.begin(), enemy_names.end(), c) != enemy_names.end();
    
    // deleting the tile
    delete grid[x][y];
    
    // adding enemy
    if (isCell) {
        grid[x][y] = new Cell(c, x, y);
    } else if (isEnemy) {
        grid[x][y] = Enemy::createEnemy(c, x, y);
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
        grid[x][y] = new Gold("GN", nullptr,x,y);
    } else if (c == "7") {
        grid[x][y] = new Gold("GS", nullptr,x,y);
    } else if (c == "8") {
        grid[x][y] = new Gold("GH", nullptr,x,y);
    } else if (c == "9") {
        grid[x][y] = new Gold("GD", nullptr,x,y);
    } else if (c == "@") {
        grid[x][y] = nullptr;
    }
    
    // notifying display
    dis->notify(grid[x][y]);
}

void Floor:: print(){
    dis->print();
}

string Floor:: getMes() {
    return mes;
}




// move all enemies randomly
void Floor:: moveEnemies() {
    // sort
    sort(Enemies.begin(), Enemies.end(), cmpEnemies);
    
    // move
    for (int i = 0; i < Enemies.size(); ++i) {
        while (true) {
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
    }
}

void Floor:: movePlayer(Player* pc, std::string dir){
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
    vector<string> walkable = {"G", ".", "+", "#"}; // Names of Tings that can step on
    string whatTo = grid[x_new][y_new]->getName(); // Name of Thing pc want to step on
    if (find(walkable.begin(), walkable.end(), whatTo) != walkable.end()) {
        grid[x_pc][y_pc] = pc->getOn();
        pc->setOn(whereTo);
        grid[x_new][y_new] = pc;
        pc->setX(x_new);
        pc->setY(y_new);
    }
    
    // Now we "DON'T" let pc pick up a gold yet!!!
}

// pick up gold; enemies in radius attack the pc; Dragon attack pc; get gold from dead enemies; delete dead enemies;
void Floor:: check(Player* pc) {
    Thing *sOn = pc->getOn(); // what "I" am standing on
    if (sOn->getName()[0] == 'G'){
        int x = pc->getX();
        int y = pc->getY();
        pc->addGold(sOn->getValue());
        delete pc->getOn();
        Thing *nt = new Cell(".", x, y);
        pc->setOn(); ////////////////////
        
    }
}


// randomly generate things (This is called when no map has been provided)

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
    int pcount = 0;
    while (pcount < 10) {
        srand(time(NULL));
        int p = rand()%6; // p is a random number from 0--5
        while (true) {
            string pn = to_string(p);
            getPos(x, y);
            if (grid[x][y]->getName() == ".") {
                init(x, y, pn);
            }
        }
    }
    //////////////////////////////
}


// what pc do
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
    string name = grid[x][y]->getName();
    if (find(enemy_names.begin(), enemy_names.end(), name) != enemy_names.end()) {
        pc->attack(*grid[x][y]);
    }
}

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
        pc->use(grid[x][y]);
    }
}
    



