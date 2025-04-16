#include "rewards/reward_factory.h"
#include "items/item_factory.h"

std::unique_ptr<Reward> RewardFactory::createRandomReward() {
    unsigned int percent = Random::getRandomPercent();

    if (percent <= 60) {
        //TODO: add tables for reward types and reward values 
        return std::make_unique<StatReward>("ATK", 1);
    } else {
        //Item item("Sword");
        auto item = ItemFactory::createRandomItem(1);
        return std::make_unique<ItemReward>(std::move(item));
    }
}