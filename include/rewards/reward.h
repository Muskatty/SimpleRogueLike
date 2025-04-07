#ifndef REWARD_H
#define REWARD_H

#include "player.h"
#include <string>

class Reward {
public:

    virtual ~Reward() {};

    virtual void applyReward(Player& player) = 0;
    virtual std::string getDescription() const = 0;

};

#endif