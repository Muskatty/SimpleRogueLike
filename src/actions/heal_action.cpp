#include "actions/heal_action.h"

void HealAction::execute(Mob* enemy, Player* player) {
    if (!enemy || !player) {
        return;
    }

    player->heal();

    if (enemy->getHp() > 0) {
        player->getDamaged(enemy->getAtk());
    }

    return;
}