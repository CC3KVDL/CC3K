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
    std::shared_ptr<Thing> owner;
    
    public:
    Gold(std::string name, int x, int y, std::shared_ptr<Thing> owner = nullptr);
    void setOwner(std::shared_ptr<Thing> t);
    std::shared_ptr<Thing> getOwner();
    int getValue();
    ~Gold();
};

#endif /* gold_h */
