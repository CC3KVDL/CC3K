//
//  elf.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef elf_h
#define elf_h

#include "enemy.h"

class Elf: public Enemy {
public:
    Elf(int x, int y);
    void attack(Player &p) override;
    void hurt(Player &p);
    ~Elf();
};

#endif /* elf_h */
