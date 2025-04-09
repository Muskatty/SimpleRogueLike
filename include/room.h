#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <memory>
#include "mobs/mob.h"
#include "util/random.h"

#define MOB_ROOM_PERCENT 100

enum RoomType {
    MOBS_ROOM = 1,
    TRADER_ROOM,
};

class Room {
protected:
public:
    std::vector<std::unique_ptr<Mob>> enemies;
    //create empty room
    Room() {};
    //create initialized room(with mobs or trader)
    Room(int lvl);
    void generateRoom(int lvl);
    bool hasEnemies();
};

#endif