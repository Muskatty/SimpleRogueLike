#include "mobs/mob.h"

int Mob::get_damaged(int damage) {
    this->hp -= damage;
    if (this->hp <= 0) {
        return -1;
    }

    return 0;
}