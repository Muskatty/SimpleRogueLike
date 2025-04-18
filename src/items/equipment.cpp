#include "items/equipment.h"

std::unique_ptr<Item> Equipment::equip(EquipmentSlot slot, std::unique_ptr<Item> item) {
    if (!item) {
        return nullptr;
    }

    std::unique_ptr<Item> prevItem;
    prevItem = std::move(this->slots[slot]);
    this->slots[slot] = std::move(item);
    return prevItem;
}

Item* Equipment::getItem(EquipmentSlot slot) {
    auto &ptr = slots[slot];
    return ptr.get();
}

unsigned int Equipment::getDamage() const {
    auto it = this->slots.find(EquipmentSlot::WEAPON);
    if (it == slots.end() || !it->second) {
        return 0;
    }
    Weapon* weapon = dynamic_cast<Weapon*>(it->second.get());
    return weapon->getDamage();
}