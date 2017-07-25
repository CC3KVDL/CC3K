#include <iostream>
#include "display.h"

using namespace std;

Display::Display() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            map[i][j] = ' ';
        }
    }
}

void Display::notify(shared_ptr<Thing> t){
    int x = t->getX();
    int y = t->getY();
    char new_char = t->getName()[0];
    map[x][y] = new_char;
}

void Display::print() const{
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

Display::~Display() {}

