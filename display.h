#ifndef display_h
#define display_h

#include "thing.h"

class Thing;

class Display {
    char map[25][79];
public:
    Display();
    void notify(std::shared_ptr<Thing> t);
    void print();
    ~Display();
};

#endif /* display_h */

