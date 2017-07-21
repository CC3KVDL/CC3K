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
    Thing* owner;
    
    public:
    Gold(std::string name, int x, int y, Thing* owner = nullptr);
    void setOwner(Thing *t);
    Thing *getOwner();
    int getValue();
    ~Gold();
};

#endif /* gold_h */
