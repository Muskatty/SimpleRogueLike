#ifndef ITEM_REWARD_H
#define ITEM_REWARD_H

#include "items/item.h"
#include "reward.h"

class ItemReward : public Reward {
private:
    std::unique_ptr<Item> item;
public:
    //ItemReward(const Item item) : item(item) {};
    //ItemReward(std::string itemname) : item(Item(itemname)) {};
    ItemReward(std::unique_ptr<Item> _item) : item(std::move(_item)) {};

    void applyReward(Player &player) override;
    std::string getDescription() const override;
};

#endif