#ifndef BATTLE_PROCESSOR_H
#define BATTLE_PROCESSOR_H

#include "player.h"
#include "mobs/mob_factory.h"

enum battle_result {
    MOB_DEAD = -1,
    ALL_ALIVE,
    PLAYER_DEAD,
};

class BattleProcessor {
public:
    int processBattle(Mob &enemy, Player &player);
};

#endif