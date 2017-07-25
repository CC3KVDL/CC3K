#include "goblin.h"
#include <cmath>
using namespace std;

Goblin::Goblin(): Player{"@Goblin", 110, 15, 20}{}

    
string Goblin::hurt(Enemy &e) {
  int hurt = ceil(100 * e.getAtk() / (100 + def));
  string m;
  if (e.getName()=="Oorcs"){
    addHp(-hurt*1.5);
    m = m + e.getName().substr(1) +  " deals " + to_string(hurt) + " damage to PC . ";
  }else{
    addHp(-hurt);
    m = m + e.getName().substr(1) +  " deals " + to_string(hurt) + " damage to PC . ";
  }
    return m;
}

Goblin::~Goblin(){}

