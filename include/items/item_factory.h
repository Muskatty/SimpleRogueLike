#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include "items/item.h"
#include "items/weapons/weapon_factory.h"
#include <memory>

class ItemFactory {
public:
    static std::unique_ptr<Item> createRandomItem(int lvl);
};

#endif