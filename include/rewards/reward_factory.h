#ifndef REWARD_FACTORY_H
#define REWARD_FACTORY_H

#include "reward.h"
#include "item_reward.h"
#include "stat_reward.h"
#include "util/random.h"
#include <memory>

class RewardFactory {
public:
    static std::unique_ptr<Reward> createRandomReward();
};

#endif