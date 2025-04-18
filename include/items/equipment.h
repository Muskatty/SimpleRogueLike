#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "items/item.h"
#include "items/weapons/weapon.h"
#include <unordered_map>
#include <memory>

class Equipment {
private:
    std::unordered_map<EquipmentSlot, std::unique_ptr<Item>> slots;
public:
    Equipment() /* : slots {
        {EquipmentSlot::HEAD, nullptr},
        {EquipmentSlot::BODY, nullptr},
        {EquipmentSlot::HANDS, nullptr},
        {EquipmentSlot::LEGS, nullptr},
        {EquipmentSlot::WEAPON, nullptr}
    }*/ {};

    //return Item that was in slot previously
    std::unique_ptr<Item> equip(EquipmentSlot slot, std::unique_ptr<Item> item);
    Item* getItem(EquipmentSlot slot);
    //returns all damage bonuses from equipment
    unsigned int getDamage() const;
};

#endif