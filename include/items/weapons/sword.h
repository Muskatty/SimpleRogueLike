#ifndef SWORD_H
#define SWORD_H

#include "items/weapons/weapon.h"

class Sword: public Weapon {
public:
    ~Sword() {};
    Sword(std::string _name, WeaponStats _stats) : Weapon(_name, _stats) {};
};

#endif