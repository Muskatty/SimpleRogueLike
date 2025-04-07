#include "mobs/mob.h"

int Mob::getDamaged(int damage) {
    this->hp -= damage;
    if (this->hp <= 0) {
        return -1;
    }

    return 0;
}