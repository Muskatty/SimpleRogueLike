#include <iostream>
#include <string>
#include <memory>
#include "game.h"
#include "util/random.h"
#include "rewards/reward_factory.h"


int main() {
    std::unique_ptr<Player> pl(new Player("Maksik"));
    Random::initialize();
    while(true) {
        if (battle(pl.get()) == 1) {
            printf("You're dead and cannot continue...\n");
            break;
        } else {
            auto reward = RewardFactory::createRandomReward();
            std::cout << "You got rewarded with:\n" << reward->getDescription() << "\n";
            reward->applyReward(*pl.get());
        }
    }
}
