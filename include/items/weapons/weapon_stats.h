#ifndef WEAPON_STATS_H
#define WEAPON_STATS_H

#include <array>
#include <cmath>
#include "util/math.h"

struct WeaponMods {
    double damageModifier;
    double critChanceModifier;
    double critMultiModifier;
};

struct WeaponStats {
    unsigned int damage;
    unsigned int critChance;
    double critMulti;
};

constexpr WeaponStats baseStats {
    5,
    5,
    1.5
};

constexpr int maxWeaponTypes = 5;

enum WeaponType {
    SWORD,
    AXE,
    DAGGER,
    BOW,
    HAMMER,
};

constexpr std::array<WeaponMods, maxWeaponTypes> weaponModsTable = {{
    //Sword
    {1.0,   1.0,    1.0},
    //Axe
    {1.05,  0.8,    1.0},
    //Dagger
    {0.8,   0.75,   1.5},
    //Bow
    {0.9,   2.0,    0.9},
    //Hammer
    {1.15,  0.5,    2.0},
}};

constexpr WeaponStats getWeaponStats(WeaponType type) {
    if (type >= maxWeaponTypes) {
        //TODO: add exception handling if necessary
        return {0, 0, 0};
    }

    return {Math::roundToUint(baseStats.damage * weaponModsTable[type].damageModifier),
            Math::roundToUint(baseStats.critChance * weaponModsTable[type].critChanceModifier),
            baseStats.critMulti * weaponModsTable[type].critMultiModifier};
}

#endif