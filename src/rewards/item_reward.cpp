#include "rewards/item_reward.h"

void ItemReward::applyReward(Player &player) {
    auto item = std::make_unique<Item>(this->item);
    player.addItem(std::move(item));
}

std::string ItemReward::getDescription() const {
    return "Item: " + this->item.getName();
}