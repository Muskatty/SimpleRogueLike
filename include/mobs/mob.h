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

    int get_damaged(int damage);
    
    int get_atk() {return atk;};
    std::string get_name() {return name;};
    int get_hp() {return hp;};
    int get_max_hp() {return max_hp;};
};

#endif