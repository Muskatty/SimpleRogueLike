cmake_minimum_required(VERSION 3.10)
project(SimpleRogueLike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
    src/player.cpp
    src/room.cpp
    src/mobs/mob.cpp
    src/mobs/goblin.cpp
    src/mobs/orc.cpp
    src/mobs/troll.cpp
    src/rewards/item_reward.cpp
    src/rewards/stat_reward.cpp
    src/rewards/reward_factory.cpp
    src/processors/battle_processor.cpp
    src/processors/room_processor.cpp
    src/util/random.cpp
)

add_executable(Rogalik ${SOURCES})

target_include_directories(Rogalik PRIVATE ${PROJECT_SOURCE_DIR}/include)
