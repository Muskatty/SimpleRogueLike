#ifndef ITEM_REWARD_H
#define ITEM_REWARD_H

#include "items/item.h"
#include "reward.h"

class ItemReward : public Reward {
private:
    Item item;
public:
    ItemReward(const Item item) : item(item) {};
    ItemReward(std::string itemname) : item(Item(itemname)) {};

    void applyReward(Player &player) override;
    std::string getDescription() const override;
};

#endif