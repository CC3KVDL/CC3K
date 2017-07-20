//
//  floor.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <cstdlib>
#include "floor.h"
#include "cell.h"

using namespace std;

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

void Floor:: readMap(string filename) {
    ifstream file{filename};
    char cell;
    int gdX, gdY, dX, dY;
    for (int i = 0; i < 25; ++ i) {
        for (int j = 0; j < 79; ++ j) {
            file >> cell;
            if (cell == '9') {
                gdX = i;
                gdY = j;
            }
            if (cell == 'D') {
                dX = i;
                dY = j;
            }
            inti(i, j, cell);
        }
    }
    grid[gdX][gdY]->setOwner(grid[dX][dY]);
}


void Floor:: init(int x, int y, char c) {
    delete grid[x][y];
    
    if (c == '-') {
        grid[x][y] = new Cell("-",x,y);
    } else if (c == '|') {
        grid[x][y] = new Cell("|",x,y);
    } else if (c == '+') {
        grid[x][y] = new Cell("+"x,y);
    } else if (c == '#') {
        grid[x][y] = new Cell("#",x,y);
    } else if (c == '\\') {
        grid[x][y] = new Cell("\\",x,y);
    } else if (c == '.') {
        grid[x][y] = new Cell(".",x,y);
    } else if (c ==' ') {
        grid[x][y] = new Cell(" ",x,y);
    } else if (c == '0') {
        grid[x][y] = new Potion("PRH",x,y);
    } else if (c == '1') {
        grid[x][y] = new Potion("PBA",x,y);
    } else if (c == '2') {
        grid[x][y] = new Potion("PBD",x,y);
    } else if (c =='3') {
        grid[x][y] = new Potion("PPH",x,y);
    } else if (c == '4') {
        grid[x][y] = new Potion("PWA",x,y);
    } else if (c =='5') {
        grid[x][y] = new Potion("PWD",x,y);
    } else if (c == '6') {
        grid[x][y] = new Gold("GN", nullptr,x,y);
    } else if (c == '7') {
        grid[x][y] = new Gold("GS", nullptr,x,y);
    } else if (c =='8') {
        grid[x][y] = new Gold("GH", nullptr,x,y);
    } else if (c == '9') {
        grid[x][y] = new Gold("GD", nullptr,x,y);
    } else if (c == '@') {
        grid[x][y] = nullptr;
    } else if (c == 'M') {
        grid[x][y] = new Merchant(x,y);
    } else if (c =='L') {
        grid[x][y] = new Halfling(x,y);
    } else if (c =='D') {
        grid[x][y] = new Dragon(x,y);
    } else if (c == 'E') {
        grid[x][y] = new Elf(x,y);
    } else if (c == 'W') {
        grid[x][y] = new Dwarf(x,y);
    } else if (c == 'H') {
        grid[x][y] = new Human(x,y);
    } else if (c =='O') {
        grid[x][y] = new Orcs(x,y);
    }
    
    dis->notify(grid[x][y]);
}

void Floor:: print(); // print out the current map
string Floor:: getMes() {
    return mes;
}


bool sortEnemies(Enemy *a, Enemy *b) {
    if (a->getX() > b->getX()) {
        return true;
    } else if (a->getX() == b->getX()) {
        return a->getY() > b->getY();
    } else {
        return false;
    }
}


void Floor:: moveEnemies() { // move all enemies randomly
    // sort
    sort(Enemies.begin(), Enemies.end(), sortEnemies);
    
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
                std:: swap(grid[x][y], grid[v1+x][v2+y]);
                dis->notify(grid[x][y]);
                dis->notify(grid[v1+x][v2+y]);
                break;
            }
            
        }
    }
}


void Floor:: movePlayer(Player* pc, std::string dir); // move pc to a direction
void Floor:: check(); // enemies in radius attack the pc; get gold from dead enemies; delete dead enemies;


// randomly generate things

void Floor::spawnEverything(Player *pc){
    // set player
    int x, y, chmbr;
    chmbr = getPos(x, y);
    pc->setOn(grid[x][y]);
    grid[x][y] = pc;
    
    // set stairway
    while (getPos(x, y) == chmbr){}
    init(x,y,'\\');
    
    // set potions
    int pcount = 0;
    while (pcount < 10) {
        srand(time(NULL));
        int p = rand()%6; // p is a random number from 0--5
        string p_name; // Denote potion type
        if (p == 0) {
            p_name = 
        }
    }
    
}

void Floor:: randomPlayer(Player* pc){
    int x;
    int y;
    while (true) {
        getPos(x, y);
        if (grid[x][y]->getName() == ".") {
            pc->setOn(grid[x][y]);
            grid[x][y] = pc;
            break;
        }
    }
}


void Floor:: randomGold(); // randomly create gold
void Floor:: randomPotion(); // randomly create potions
void Floor:: randomEnemy(); // randomly create enemies

void Floor:: attackEnemy(Player *pc, std::string dir);
void Floor:: usePotion(Player *pc, std::string dir);



