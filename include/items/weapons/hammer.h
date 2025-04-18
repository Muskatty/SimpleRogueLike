#ifndef HAMMER_H
#define HAMMER_H

#include "items/weapons/weapon.h"

class Hammer: public Weapon {
public:
    ~Hammer() {};
    Hammer(std::string _name, WeaponStats _stats) : Weapon(_name, _stats) {};
};

#endif