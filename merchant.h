//
//  merchant.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef merchant_h
#define merchant_h

#include "enemy.h"

class Merchant: public Enemy {
public:
    Merchant(int x, int y);
    std::string attack(Thing& t) override;
    ~Merchant();
};

#endif /* merchant_h */

