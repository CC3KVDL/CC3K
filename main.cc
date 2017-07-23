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
#include "floor.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    while (true) {
        cout << "======================================================" << endl;
        cout << "~~~~~~  ~~~~~~~~~  ~~~~~~~~     ~~~~~~~~~  ~~~~  ~~~~~" << endl;
        cout << "~~~~~ ~~~~~~~~~~ ~~~~~~~~~ ~~~~~  ~~~~~~~ ~~~~ ~~~~~~~" << endl;
        cout << "~~~~ ~~~~~~~~~~ ~~~~~~~~~~~~~~~~ ~~~~~~~~ ~~~ ~~~~~~~~" << endl;
        cout << "~~~~ ~~~~~~~~~~ ~~~~~~~~~~~~~   ~~~~~~~~~   ~~~~~~~~~~" << endl;
        cout << "~~~~ ~~~~~ ~~~~ ~~~~  ~~~~~~~~~~ ~~~~~~~~ ~~  ~~~~~~~~" << endl;
        cout << "~~~~~    ~~~~~~~~   ~~~~~~  ~~~   ~~~~~~~ ~~~~~  ~~~~~" << endl;
        cout << "======================================================" << endl;
        cout << endl;
        cout << "The world were zeros and ones before you came," << endl;
        cout << "Three brave programmers build this game," << endl;
        cout << "Five large chambres are the general frame," << endl;
        cout << "There hides enemies that can't be tamed." << endl;
        cout << "Fighting and collecting is how you play," << endl;
        cout << "Climbing to the sixth floor is your final aim," << endl;
        cout << "Now that you shall choose your name." << endl;
        cout << "Shout out your race or just be lame(q)." << endl;
        cout << "s-shade" << endl << "d-drow" << endl << "v-vampire" << endl << "g-goblin" << endl <<"t-troll" << endl;
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
        
        while (true) {
            Display dis;
            Floor f(&dis);
            bool restart = false;
            
            // generate full floor
            if (argc == 1) { // no argument
                f.readMap(me);
                f.spawnEverything(me);
            } else { // with argument
                f.readMap(me, argv[1]);
            }
            
            // print the map and message
            f.print(me, floor);
            cout<< "Player enters floor: " << floor << endl;
            
            
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
                } else if (command == "r" ) {
                    restart = true;
                    break;
                } else if (command == "q" ) {
                    cout << "Game Over" << endl;
                    f.freePlayer(me); // make sure grid has access to a valid address
                    delete me;
                    return 0;
                } else {
                    cout << "Invalide command" << endl;
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
                    cout << "Game Over" << endl;
                    cout << "You have scored: " << me->getGold() << endl;
                    f.freePlayer(me); // make sure me is not deleted with Floor
                    delete me;
                    return 0;
                }
                
                // at stair / win
                if (me->getOn()->getName() == "\\") {
                    if (floor == 5) {
                        cout << "Win!" << endl;
                        cout << "You have scored: " << me->getGold() << endl;
                        f.freePlayer(me); // make sure me is not deleted with floor
                        delete me;
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

