//
//  potion.hpp
//  CC3K
//
//  Created by Dennis on 2017-07-16.
//  Copyright © 2017 Dennis. All rights reserved.
//

#ifndef potion_h
#define potion_h


class Potion : public Thing {
  int hp;
  int atk;
  int def;
  public:
  Potion(string name, int x, int y);
  void modify(Player* p);
};


#endif /* potion_h */
