//
//  main.cpp
//  CC3K
//
//  Created by Dennis on 2017-07-13.
//  Copyright © 2017 Dennis. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include "player.h"
#include "floor.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    while (true) {
        cout << "=======================================================" << endl;
        cout << "~~~~~~~  ~~~~~~~~~  ~~~~~~~~     ~~~~~~~~~  ~~~~  ~~~~~" << endl;
        cout << "~~~~~  ~~~~~~~~~~ ~~~~~~~~~ ~~~~~  ~~~~~~~ ~~~~ ~~~~~~~" << endl;
        cout << "~~~~  ~~~~~~~~~~ ~~~~~~~~~~~~~~~~ ~~~~~~~~ ~~~ ~~~~~~~~" << endl;
        cout << "~~~~ ~~~~~~~~~~~ ~~~~~~~~~~~~~   ~~~~~~~~~   ~~~~~~~~~~" << endl;
        cout << "~~~~  ~~~~~~~~~~ ~~~~  ~~~~~~~~~~ ~~~~~~~~ ~~  ~~~~~~~~" << endl;
        cout << "~~~~~~    ~~~~~~~~   ~~~~~~  ~~~   ~~~~~~~ ~~~~~  ~~~~~" << endl;
        cout << "=======================================================" << endl;
        cout << endl;
        cout << "The world were zeros and ones before you came," << endl;
        cout << "Three smart programmers build this game," << endl;
        cout << "Five large chambres are the general frame," << endl;
        cout << "There hide creatures that can't be tamed." << endl;
        cout << "Fighting and collecting is how you play," << endl;
        cout << "Climbing to the sixth floor is your final aim," << endl;
        cout << "Now that you shall choose your race," << endl;
        cout << "Choose to quit(q) or type in your name." << endl;
        cout << "s-Shade" << endl << "d-Drow" << endl << "v-Vampire" << endl << "g-Goblin" << endl <<"t-Troll" << endl;
        string pc_type;
        cin >> pc_type;
        if (pc_type == "q") {
            cout << "Alright man. Let's get you outta here." << endl;
            return 0;
        }
        
        while (pc_type != "" &&
               pc_type != "d" &&
               pc_type != "v" &&
               pc_type != "g" &&
               pc_type != "s" &&
               pc_type != "t") {
            cout << "Oops! You cannot be something that doesn't exist! Please try to become something real!" << endl;
            cin >> pc_type;
        }
        shared_ptr<Player> me = Player::createPlayer(pc_type);
        int floor = 1;
        ifstream file;
        if (argc == 1) {
            file.open("default.txt");
        } else if (argc == 2) {
            file.open(argv[1]);
        } else {
            cout << "OMG! You have wrong number of command line arguments!" << endl;
            return 0;
        }
        
        while (true) {
            shared_ptr<Display> pdis(new Display()); // Display lalala
            Floor f(pdis);
            bool restart = false;
            
            // generate full floor
            if (argc == 1) { // no argument
                f.readMap(me, file);
                f.spawnEverything(me);
            } else { // with argument
                f.readMap(me, file);
            }
            
            // print the map and message
            f.print(me, floor);
            
            
            // read in command
            string command;
            bool moveEnemy = true;
            while (cin >> command) {
                
                
                // interprates commands
                if (command == "no" ||
                    command == "so" ||
                    command == "ea" ||
                    command == "we" ||
                    command == "ne" ||
                    command == "nw" ||
                    command == "se" ||
                    command == "sw") {
                    f.movePlayer(me, command);
                } else if (command == "u") {
                    string dir;
                    cin >> dir;
                    f.usePotion(me, dir);
                } else if (command == "a") {
                    string dir;
                    cin >> dir;
                    f.attackEnemy(me, dir);
                } else if (command == "f" ) {
                    if (moveEnemy) {
                        moveEnemy = false;
                    } else {
                        moveEnemy = true;
                    }
                }else if (command == "b"){
                    string dir;
                    cin >> dir;
                    f.buy(me, dir);
                } else if (command == "r" ) {
                    restart = true;
                    break;
                } else if (command == "q" ) {
                    cout << "Game Over" << endl;
                    f.freePlayer(me); // make sure grid has access to a valid address
                    return 0;
                } else {
                    cout << "Oh man you can't actually do that. Just try another command." << endl;
                    continue;
                }
                
                // update information and move enemies
                f.check(me);
                if (moveEnemy) {
                    f.moveEnemies();
                }
                
                // break out loop conditions
                
                // HP == 0
                if (me->getHp() <= 0) {
                    f.print(me, floor);
                    cout << "///////////////////////////////////////////////////////////////////////" << endl;
                    cout << "You are Dead!" << endl;
                    cout << "You have scored: " << me->getGold() << endl;
                    cout << "I know, I know. Those bastards are mean, aren't they. I bid you farewell," << endl << "my dear friend." << endl;
                    f.freePlayer(me); // make sure me is not deleted with Floor
                    return 0;
                }
                
                // at stair / win
                if (me->getOn()->getName() == "\\") {
                    if (floor == 5) {
                        f.print(me, floor);
                        cout << "//////////////////////////////////////////////////////////////////////" << endl;
                        cout << "You did it!" << endl;
                        cout << "You have scored: " << me->getGold() << endl;
                        cout << endl << endl;
                        cout << "\"So what next?\"" << endl << endl;
                        cout << "Asked the confused gamer," << endl << endl;
                        cout << "\"What's the point of all of this?\"" << endl << endl;
                        cout << "Suddenly the gamer heard a callous voice from above." << endl << endl;
                        cout << "\"No, there is no point in any of these, my friend. This is just like" << endl;
                        cout << "your life. You climbed and climbed, struggled and struggled, hoping " << endl;
                        cout << "that there is a light waiting for you somewhere, welcoming, eluding, " << endl;
                        cout << "restlessly flickering in the dark. You want yourself to know, deep" << endl;
                        cout << "down, it is there somewhere. Right?\"" << endl << endl;
                        cout << "\"So you beat on, boats against the current, borne back ceaselessly" << endl;
                        cout << "into the past." << endl << endl;
                        f.freePlayer(me); // make sure me is not deleted with floor
                        return 0;
                    }
                    ++ floor;
                    
                    // new ark && def
                    me->initStatus();
                    
                    break;
                }
                
                // troll adds 5 hp every turn
                if (me->getName() == "@Troll") {
                    me->addHp(5);
                }
                
                // print new map
                f.print(me, floor);
                
                
            }
            
            if (restart) break;
        }
    }
}

