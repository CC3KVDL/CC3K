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
            srand(time(NULL));
            int v = rand()%4; // generate 0~4
            if (v == 0) {
                int v0 = rand()% ;
                
            } else if (v == 1) {
                
            } else if (v == 2) {
                
            } else if (v == 3) {
                
            } else {
                
            }
        } else { // with argument
            
        }
    }
}
