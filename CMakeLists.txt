cmake_minimum_required(VERSION 3.10)
project(SimpleRogueLike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/game.cpp
    src/main.cpp
    src/player.cpp
    src/mobs/mob.cpp
    src/mobs/goblin.cpp
    src/mobs/orc.cpp
    src/mobs/troll.cpp
)

add_executable(Rogalik ${SOURCES})

target_include_directories(Rogalik PRIVATE ${PROJECT_SOURCE_DIR}/include)