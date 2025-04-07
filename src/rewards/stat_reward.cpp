#include "rewards/stat_reward.h"

void StatReward::applyReward(Player& player) {
    player.increaseStat(statName, statBonus);
}

std::string StatReward::getDescription() const {
    return "Upgraded " + this->statName + " by " + std::to_string(this->statBonus);
}