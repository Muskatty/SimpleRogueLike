#include "processors/battle_processor.h"

#define SCREEN_SIZE 50

//Macro to print string "a  ...  b" of length SCREEN_SIZE
#define JUSTIFY(a, b) printf("%s%*s\n",a.c_str(), (int)(SCREEN_SIZE - a.length()), b.c_str())

void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    printf("\x1B[2J\x1B[H");
}

void print_stats(Player *p, Mob *e) {
    //print names
    JUSTIFY(p->getName(), e->getName());

    std::string t1, t2;
    t1 ="HP: " + std::to_string(p->getHp()) + "/" + std::to_string(p->getMaxHp());
    t2 ="HP: " + std::to_string(e->getHp()) + "/" + std::to_string(e->getMaxHp());
    JUSTIFY(t1, t2);

    printf("LVL:%d %d/%d\n", p->getLvl(), p->getExp(), p->getExpBound());

    t1 = "ATK: " + std::to_string(p->getAtk());
    t2 = "ATK: " + std::to_string(e->getAtk());
    JUSTIFY(t1, t2);
    printf("Choose an action!\n");
    printf("1.Attack\n");
    printf("2.Heal\n");
}

//TODO: Maybe move it to battleProcessor?
void give_exp(Player* player, Mob *enemy) {
    int given_exp = (int)pow((double)enemy->getMaxHp(), 0.85);
    player->earnExp(given_exp);
    return;
}

//TODO: Change handleAction to separate Interface/Class
//return 0 - nobody's dead, 1 - player is dead, -1 - mob is dead
int handleAction(Player* pl, Mob *e, std::string action) {
    int a = stoi(action);
    int res = 0;
    switch(a) {
    case 1:
        res = e->getDamaged(pl->getAtk());
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

    res = pl->getDamaged(e->getAtk());

    return -res;
}

int BattleProcessor::processBattle(Mob& enemy, Player& player) {
    if (player.getHp() <= 0) {
        printf("Can't fight! You're DEAD!\n"); //Don't want to use print straight to console, maybe create separate class for logging later
        return 1;
    }

    int res;
    std::string action;
    while(true) {
        print_stats(&player, &enemy);
        std::cin >> action;
        if (action != "1" && action != "2") {
            clear();
            printf("Wrong option!\n");
            continue;
        }
        res = handleAction(&player, &enemy, action);
        clear();
        if (res != 0) break;
    }
    if (res == PLAYER_DEAD) {
        printf("You lost!\n");
    } else {
        printf("You won!\n");
        give_exp(&player, &enemy);
    }
    return res;
}