//
//  thing.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-14.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef thing_h
#define thing_h

class Thing {
    char name;
    int x;
    int y;
public:
    Thing(char name, int x, int y, bool attackable);
    void printName();
    char getName();
    virtual ~Thing();
};

#endif /* thing_h */
