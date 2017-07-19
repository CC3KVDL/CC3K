//
//  main.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-13.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "player.h"
#include "floor.h"

using namespace std;

void givePos(int& x, int& y) {
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
}



int main(int argc, const char * argv[]) {
    cout << "Please choose your race or choose quit." << endl;
    string pc_type;
    Player * me = new Player; // Pointer to Player
    cin >> pc_type;
    if (pc_type == "q") {
        return 0;
    }
    
    while (pc_type != "d" ||
           pc_type != "v" ||
           pc_type != "g" ||
           pc_type != "s" ||
           pc_type != "t") {
        cout << "Oops! You cannot be something that doesn't exist! Please try to become something real!" << endl;
        cin >> pc_type;
    }
    me->createPlayer(pc_type);
    int floor = 1;
    
    while (true) {
        Display dis;
        if (argc == 1) { // no argument
            Floor f("default.txt", &dis);
            
            
        } else { // with argument
            
        }
    }
}
