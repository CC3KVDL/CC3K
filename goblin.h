#ifndef goblin_h
#define goblin_h

#include "player.h"
#include "thing.h"
#include <string>

class Goblin: public Player {
public:
    Goblin();
    std::string hurt(Enemy &e) override;
    ~Goblin();
};

#endif /* goblin_h */

