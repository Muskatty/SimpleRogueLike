#include "rewards/item_reward.h"

void ItemReward::applyReward(Player &player) {
    //player.addItem(std::move(item));
    player.equipItem(std::move(item));
}

std::string ItemReward::getDescription() const {
    return "Item: " + this->item->getName();
}