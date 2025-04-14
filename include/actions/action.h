#ifndef ACTION_H
#define ACTION_H

#include "mobs/mob.h"
#include "player.h"

class Action {
public:
    virtual ~Action() {};
    virtual void execute(Mob *enemy, Player *player) = 0;
};

#endif