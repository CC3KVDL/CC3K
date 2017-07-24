//
//  dragon.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-18.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef dragon_h
#define dragon_h

#include <memory>
#include "enemy.h"

class Dragon: public Enemy {
    std::shared_ptr<Thing> hoard;
    
public:
    Dragon(int x, int y);
    ~Dragon();
    void setHoard(std::shared_ptr<Thing> t) override;
    std::shared_ptr<Thing> getHoard() override;
};

#endif /* dragon_h */
