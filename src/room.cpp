#include "room.h"
#include "mobs/mob_factory.h"

Room::Room(int lvl) {
    this->generateRoom(lvl);
}

void Room::generateRoom(int lvl) {
    unsigned int room = Random::getRandomPercent();
    if (room <= MOB_ROOM_PERCENT) {
        unsigned int mob_number = Random::getRandomOneToN(5);
        for (int i = 0; i < mob_number; i++) {
            auto mob = std::make_unique<Mob>(*MobFactory::createRandomMob(lvl));
            this->enemies.push_back(std::move(mob)); //Seems sloppy, check for memory leaks
        }
    } else { //Trader room
        //do nothing... yet
    }
}

bool Room::hasEnemies() {
    return !this->enemies.empty();
}