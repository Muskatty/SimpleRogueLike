#include "mobs/mob_factory.h"

std::unique_ptr<Mob> MobFactory::createRandomMob(int lvl) {
    int rnd = Random::getRandomOneToN(std::min(3, lvl));

    switch (rnd)
    {
    case MOB_GOBLIN:
        return std::make_unique<Goblin>();
    case MOB_ORC:
        return std::make_unique<Orc>();
    case MOB_TROLL:
        return std::make_unique<Troll>();
    default:
        return std::make_unique<Goblin>();
    }
}