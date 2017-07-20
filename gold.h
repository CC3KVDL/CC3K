//
//  gold.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef gold_h
#define gold_h

#include "thing.h"
#include "dragon.h"

class Gold: public Thing {
    int value;
    Dragon* owner;
    
    public:
    Gold(std::string, int x, int y);
    int getValue();
    Dragon* getDragon();
    ~Gold();
};

#endif /* gold_h */
