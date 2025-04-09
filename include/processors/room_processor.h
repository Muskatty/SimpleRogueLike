#ifndef ROOM_PROCESSOR_H
#define ROOM_PROCESSOR_H

#include "room.h"
#include "player.h"

class RoomProcessor {
public:
    void processRoom(Room &room, Player &player);
};

#endif