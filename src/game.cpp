#include "game.h"
#include <cmath>
#include <iostream>
#include <memory>


void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    printf("\x1B[2J\x1B[H");
}

void print_stats(Player *p, Mob *e) {
    //print names
    JUSTIFY(p->get_name(), e->get_name());

    std::string t1, t2;
    t1 ="HP: " + std::to_string(p->get_hp()) + "/" + std::to_string(p->get_max_hp());
    t2 ="HP: " + std::to_string(e->get_hp()) + "/" + std::to_string(e->get_max_hp());
    JUSTIFY(t1, t2);

    printf("LVL:%d %d/%d\n", p->get_lvl(), p->get_exp(), p->get_exp_bound());

    t1 = "ATK: " + std::to_string(p->get_atk());
    t2 = "ATK: " + std::to_string(e->get_atk());
    JUSTIFY(t1, t2);
    printf("Choose an action!\n");
    printf("1.Attack\n");
    printf("2.Heal\n");
}

void give_exp(Player* player, Mob *enemy) {
    int given_exp = (int)pow((double)enemy->get_max_hp(), 0.85);
    player->earn_exp(given_exp);
    return;
}

int battle(Player *player) {
    if (player->get_hp() <= 0) {
        printf("Can't fight! You're DEAD!\n");
        return 1;
    }

    std::unique_ptr<Mob> enemy(MobFactory::createRandomMob(player->get_lvl()));
    int res;
    std::string action;
    while(true) {
        print_stats(player, enemy.get());
        std::cin >> action;
        if (action != "1" && action != "2") {
            clear();
            printf("Wrong option!\n");
            continue;
        }
        res = handle_action(player, enemy.get(), action);
        clear();
        if (res != 0) break;
    }
    if (res == PLAYER_DEAD) {
        printf("You lost!\n");
    } else {
        printf("You won!\n");
        give_exp(player, enemy.get());
    }
    return res;
}

//return 0 - nobody's dead, 1 - player is dead, -1 - mob is dead
int handle_action(Player* pl, Mob *e, std::string action) {
    int a = stoi(action);
    int res = 0;
    switch(a) {
    case 1:
        res = e->get_damaged(pl->get_atk());
        break;
    case 2:
        pl->heal();
        break;
    default:
        break;
    }

    if (res == -1) {
        return res;
    }

    res = pl->get_damaged(e->get_atk());

    return -res;
}