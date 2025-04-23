#include "processors/battle_processor.h"
#include "actions/action_factory.h"
#include "util/concole.h"

void print_stats(Player *p, Mob *e) {
    //print names
    JUSTIFY(p->getName(), e->getName());

    std::string t1, t2;
    t1 ="HP: " + std::to_string(p->getHp()) + "/" + std::to_string(p->getMaxHp());
    t2 ="HP: " + std::to_string(e->getHp()) + "/" + std::to_string(e->getMaxHp());
    JUSTIFY(t1, t2);

    printf("LVL:%d %d/%d\n", p->getLvl(), p->getExp(), p->getExpBound());

    t1 = "ATK: " + std::to_string(p->getHitPower());
    t2 = "ATK: " + std::to_string(e->getAtk());
    JUSTIFY(t1, t2);
    printf("Choose an action!\n");
    printf("%d.Attack\n",  static_cast<int>(ActionType::ATTACK_ACTION));
    printf("%d.Heal\n",  static_cast<int>(ActionType::HEAL_ACTION));
    printf("%d.Check inventory\n", static_cast<int>(ActionType::INVENTORY_ACTION));
}

//TODO: Maybe move it to battleProcessor?
void give_exp(Player* player, Mob *enemy) {
    int given_exp = (int)pow((double)enemy->getMaxHp(), 0.85);
    player->earnExp(given_exp);
    return;
}

int BattleProcessor::processBattle(Mob& enemy, Player& player) {
    if (player.getHp() <= 0) {
        printf("Can't fight! You're DEAD!\n"); //Don't want to use print straight to console, maybe create separate class for logging later
        return 1;
    }

    std::string actionStr;
    int actionType;
    while(enemy.getHp() > 0 && player.getHp() > 0) {
        print_stats(&player, &enemy);
        std::cin >> actionStr;
        try {
            actionType = std::stoi(actionStr);
        }
        catch (std::invalid_argument const& ex) {
            clear();
            printf("Wrong option!\n");
            continue;
        }

        //validate action type
        if (actionType >= ActionType::INVALID_ACTION || actionType < ActionType::ATTACK_ACTION) {
            clear();
            printf("Wrong option!\n");
            continue;
        }

        auto action = ActionFactory::createAction((ActionType)actionType);
        action->execute(&enemy, &player);
        
        clear();
    }

    if (player.getHp() <= 0) {
        printf("You lost!\n");
    } else {
        printf("You won!\n");
        give_exp(&player, &enemy);
    }
    return player.getHp() <= 0 ? PLAYER_DEAD : MOB_DEAD;
}