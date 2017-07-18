//
//  main.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-13.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Please choose your race or choose quit." << endl;
    string pc_type;
    Player * me; // Pointer to Player. this is a unique ptr
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
    me = new Player{pc_type};

    
    while (true) {
        
    }
}
