#ifndef MOB_FACTORY_H
#define MOB_FACTORY_H

#include "mob.h"
#include "goblin.h"
#include "orc.h"
#include "troll.h"
#include "util/random.h"
#include "memory"
#include <cstdlib>
#include <ctime>

enum MobTypes {
    MOB_GOBLIN = 1,
    MOB_ORC,
    MOB_TROLL,
};

class MobFactory {
public:
    static std::unique_ptr<Mob> createRandomMob(int lvl);
};

#endif