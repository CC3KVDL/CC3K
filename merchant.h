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
    Merchant();
    void attack(Player &p);
    void hurt(Player &p);
    ~Merchant();
};

#endif /* merchant_h */
