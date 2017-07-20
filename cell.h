//
//  cell.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-19.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef cell_h
#define cell_h

#include "string"
#include "thing.h"

class Cell: public Thing {
public:
    Cell(std::string, int x, int y);
    ~Cell();
};

#endif /* cell_h */
