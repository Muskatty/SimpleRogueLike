#include <iostream>
#include <string>
#include "game.h"


int main() {
    std::string n;
    Player *pl = new Player("Maksik");
    while(true) {
        if (battle(pl) == 1) {
            printf("You're dead and cannot continue...\n");
            break;
        }
    }
}
