//
//  gold.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef gold_h
#define gold_h

class Gold {
    int value;
    Dragon* owner;
    
    public:
    int getValue();
    Dragon* getDragon();
};

#endif /* gold_h */
