#include "items/weapons/weapon_factory.h"
#include "util/random.h"

std::unique_ptr<Weapon> WeaponFactory::createWeapon(WeaponType type) {
    switch(type) {
    case SWORD:
        return std::make_unique<Sword>("Sword", getWeaponStats(type));
    case AXE:
        return std::make_unique<Axe>("Axe", getWeaponStats(type));
    case DAGGER:
        return std::make_unique<Dagger>("Dagger", getWeaponStats(type));
    case BOW:
        return std::make_unique<Bow>("Bow", getWeaponStats(type));
    case HAMMER:
        return std::make_unique<Hammer>("Hammer", getWeaponStats(type));
    default:
        return nullptr;
    }
}

std::unique_ptr<Weapon> WeaponFactory::createRandomWeapon() {
    //-1 because array is 0-indexed, add 0 to N-1 generator later maybe?
    int type = Random::getRandomOneToN(maxWeaponTypes) - 1; 

    return createWeapon(static_cast<WeaponType>(type));
}