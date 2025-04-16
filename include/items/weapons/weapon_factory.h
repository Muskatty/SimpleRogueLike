#ifndef WEAPON_FACTORY
#define WEAPON_FACTORY

#include "items/weapons/axe.h"
#include "items/weapons/dagger.h"
#include "items/weapons/hammer.h"
#include "items/weapons/sword.h"
#include "items/weapons/bow.h"
#include <memory>

class WeaponFactory {
public:
    static std::unique_ptr<Weapon> createWeapon(WeaponType type);
    static std::unique_ptr<Weapon> createRandomWeapon();
};

#endif