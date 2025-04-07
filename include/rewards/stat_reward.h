#ifndef STAT_REWARD_H
#define STAT_REWARD_H

#include "player.h"
#include "rewards/reward.h"
#include <string>

class StatReward: public Reward {
private:
    std::string statName;
    int statBonus;
public:
    StatReward(const std::string &statName, int bonus) :
        statName(statName), statBonus(bonus) {};

    void applyReward(Player& Player) override;

    std::string getDescription() const override;
};

#endif