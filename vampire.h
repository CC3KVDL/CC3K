#ifndef vampire_h
#define vampire_h

#include "player.h"
#include "thing.h"

class Vampire: public Player {
public:
    Vampire();
    std::string attack(Thing &e) override;
    ~Vampire();
};

#endif /* vampire_h */

