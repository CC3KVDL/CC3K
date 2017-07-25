#ifndef thing_h
#define thing_h

#include <memory>
#include <string>
#include "type.h"

class Player;
class Enemy;

class Thing {
    std::string name;
    int x;
    int y;
public:
    
    // Method all "thing" can call
    Thing(std::string name, int x=-1, int y=-1);
    int getX();
    int getY();
    void setX(int pos_x);
    void setY(int pos_y);
    std::string getName();
    //virtual Type getType();
    virtual ~Thing();
    
    // Virtual Methov for Player and Enemy
    virtual std::string attack(Thing &t);
    virtual int getHp();
    
    // Virtual Method only for Player
    virtual std::string use(std::shared_ptr<Thing> t);
    virtual std::string hurt(Enemy &e);
    virtual std::shared_ptr<Thing> getOn();
    virtual void setOn(std::shared_ptr<Thing> t);
    virtual bool getmKiller();
    
    // Virtual Method only for Enemy
    virtual std::string hurt(Player &p);
    virtual void setStand(bool s);
    virtual bool getStand();
    virtual void setHoard(std::shared_ptr<Thing> t);
    virtual std::shared_ptr<Thing> getHoard();

    // Virtual Method for Gold
    virtual void setOwner(std::shared_ptr<Thing> t);
    virtual int getValue();
    virtual std::shared_ptr<Thing> getOwner();
    
    // Virtual Method for Potion
    virtual void modify(Player& pc);
};

#endif /* thing_h */

