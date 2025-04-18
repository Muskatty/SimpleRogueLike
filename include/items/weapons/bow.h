#ifndef BOW_H
#define BOW_H

#include "items/weapons/weapon.h"

class Bow: public Weapon {
public:
    ~Bow() {};
    Bow(std::string _name, WeaponStats _stats) : Weapon(_name, _stats) {};
};

#endif