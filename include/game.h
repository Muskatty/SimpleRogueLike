#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "mobs/mob_factory.h"

#define SCREEN_SIZE 50

//Macro to print string "a  ...  b" of length SCREEN_SIZE
#define JUSTIFY(a, b) printf("%s%*s\n",a.c_str(), (int)(SCREEN_SIZE - a.length()), b.c_str())

enum battle_result {
    PLAYER_DEAD = 1,
    MOB_DEAD = -1
};

int battle(Player* pl);
int handleAction(Player* pl, Mob *e, std::string action);
void clear();

#endif