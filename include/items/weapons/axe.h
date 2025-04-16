#ifndef AXE_H
#define AXE_H

#include "items/weapons/weapon.h"

class Axe: public Weapon {
public:
    Axe(std::string _name, WeaponStats _stats) : Weapon(_name, _stats) {};
};

#endif