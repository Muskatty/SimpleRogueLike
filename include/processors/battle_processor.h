#ifndef BATTLE_PROCESSOR_H
#define BATTLE_PROCESSOR_H

#include "player.h"
#include "mobs/mob_factory.h"

enum battle_result {
    PLAYER_DEAD = 1,
    MOB_DEAD = -1
};

class BattleProcessor {
public:
    int processBattle(Mob &enemy, Player &player);
};

#endif