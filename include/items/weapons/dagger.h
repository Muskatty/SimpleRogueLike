#ifndef DAGGER_H
#define DAGGER_H

#include "items/weapons/weapon.h"

class Dagger: public Weapon {
public:
    Dagger(std::string _name, WeaponStats _stats) : Weapon(_name, _stats) {};
};

#endif