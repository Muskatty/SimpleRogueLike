#ifndef WEAPON_H
#define WEAPON_H

#include "items/item.h"
#include "items/weapons/weapon_stats.h"

class Weapon: public Item {
protected:
    WeaponStats stats;
public:
    Weapon() = delete;
    ~Weapon() {};
    Weapon(std::string _name, WeaponStats _stats) : Item(_name), stats(_stats) {};

    EquipmentSlot getSlot() const override {return EquipmentSlot::WEAPON;};
    unsigned int getDamage() const {return stats.damage;}; //TODO: think really hard about differences of weapons, maybe add different modifiers
                                                    // dagger - add double hit mechanic
                                                    // hammer - add stun mechanic
                                                    // axe - add bleed mechanic
                                                    // bow - add evasion mechanic
};

#endif