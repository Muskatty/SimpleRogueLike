#ifndef INVENTORY_ACTION_H
#define INVENTORY_ACTION_H

#include "actions/action.h"

class InventoryAction: public Action {
public:
    InventoryAction() {};
    ~InventoryAction() {};

    void execute(Mob *enemy, Player* player) override;
};

#endif