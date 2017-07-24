#include "vampire.h"
#include <string>
using namespace std;

Vampire::Vampire(): Player{"@Vampire", 50, 25, 25}{}

string Vampire::attack(Thing &e) {
  e.setStand(true);
  if (e.getName()=="Wdwarf"){
    addHp(-5);
  }else{
    addHp(5);
  }
  //default attack
  return e.hurt(*this);
}



Vampire::~Vampire(){}

