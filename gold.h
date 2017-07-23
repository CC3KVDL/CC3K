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
    shared_ptr<Thing> owner;
    
    public:
    Gold(std::string name, int x, int y, shared_ptr<Thing> owner = nullptr);
    void setOwner(shared_ptr<Thing> t);
    shared_ptr<Thing> getOwner();
    int getValue();
    ~Gold();
};

#endif /* gold_h */
