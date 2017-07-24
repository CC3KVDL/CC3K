#ifndef human_h
#define human_h

#include "enemy.h"

class Human: public Enemy {
public:
    Human(int x, int y);
    ~Human();
};

#endif /* human_h */

