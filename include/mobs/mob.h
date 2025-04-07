#ifndef MOB_H
#define MOB_H

#include <string>

class Mob {
protected:
    std::string name;
    int max_hp;
    int hp;
    unsigned int atk;

public:
    Mob(std::string _name, int _max_hp, int _atk)
        : name(_name), max_hp(_max_hp), hp(_max_hp), atk(_atk) {};
    
    virtual ~Mob() {};

    int getDamaged(int damage);
    
    int getAtk() {return atk;};
    std::string getName() {return name;};
    int getHp() {return hp;};
    int getMaxHp() {return max_hp;};
};

#endif