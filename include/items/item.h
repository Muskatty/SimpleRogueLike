#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "items/equipment_slot.h"

class Item {
protected:
    std::string name;
public:
    ~Item() {};
    Item(std::string _name) : name(_name) {};

    std::string getName() const {return name;};
    virtual EquipmentSlot getSlot() const = 0;
};


#endif