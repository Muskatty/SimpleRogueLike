#ifndef MOB_FACTORY_H
#define MOB_FACTORY_H

#include "mob.h"
#include "goblin.h"
#include "orc.h"
#include "troll.h"
#include "util/random.h"
#include <cstdlib>
#include <ctime>

enum MobTypes {
    MOB_GOBLIN = 1,
    MOB_ORC,
    MOB_TROLL,
};

class MobFactory {
public:
    static Mob* createRandomMob(int lvl) {
        int rnd = Random::getRandomOneToN(std::min(3, lvl));

        switch (rnd)
        {
        case MOB_GOBLIN:
            return new Goblin();
        case MOB_ORC:
            return new Orc();
        case MOB_TROLL:
            return new Troll();
        default:
            return new Goblin();
        }
    }
};

#endif