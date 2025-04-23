#include "rewards/item_reward.h"
#include "util/concole.h"
#include <iostream>

void ItemReward::applyReward(Player &player) {
    //I hate using console and input right inside this class or any other class. Need to create separate instrument for input
    // or output.
    // GLOBAL TODO: create input/output class
    Item* equipped = player.getItem(this->item->getSlot());

    bool shouldEquip = true;

    if (equipped) {
        int choice;
        std::cout << "You have " << equipped->getName() << " equipped. Would you like to equip "
                  <<  item->getName() <<" instead?\n" 
                  << "1.Yes\n" 
                  << "2.No\n";        
        
        while (true) {
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore max symbols or ignore all until we meet \n
                std::cout << "Wrong choice! Enter 1 or 2\n";
                continue;
            }
            shouldEquip = (choice == 1);
            break;
        }
    }

    if (shouldEquip) {
        player.equipItem(std::move(item));        
    } else {
        player.addItem(std::move(item));
    }

    return;
}

std::string ItemReward::getDescription() const {
    return "Item: " + this->item->getName();
}