#include "actions/inventory_action.h"
#include <iostream>

void InventoryAction::execute(Mob* enemy, Player* player) {
    if (!player) {
        return;
    }
    std::string str;
    auto inventory = player->getInventory();
    printf("Your inventory:\n");
    for (int i = 0; i < inventory.size(); i++) {
        printf("%d.%s\n", i + 1, inventory[i]->getName().c_str());
    }
    printf("Press any button to continue!\n");
    std::cin >> str;

    return;
}