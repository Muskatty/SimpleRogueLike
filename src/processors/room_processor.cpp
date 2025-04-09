#include "processors/room_processor.h"
#include "processors/battle_processor.h"
#include "rewards/reward_factory.h"

void RoomProcessor::processRoom(Room &room, Player &player) {
    if (room.hasEnemies()) {
        int maxEnemies = room.enemies.size();
        printf("You entered a room with %d enemies\n", maxEnemies);
        BattleProcessor battleProcessor;
        while (room.hasEnemies() && player.getHp() > 0) {
            printf("%d enemies left out of %d\n",room.enemies.size(), maxEnemies);
            //get first enemy in the room
            Mob &currentEnemy = *room.enemies.front();

            int res = battleProcessor.processBattle(currentEnemy, player);
            if (res == PLAYER_DEAD) {
                printf("LOL, you died");
                return;
            }
            //remove enemy from the vector if we won
            room.enemies.erase(room.enemies.begin());
        }

        auto reward = RewardFactory::createRandomReward();
        printf("You completed the room and got rewarded with:\n%s\n",reward->getDescription().c_str());
        reward->applyReward(player);
    }
}