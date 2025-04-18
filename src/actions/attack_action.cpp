#include "actions/attack_action.h"

void AttackAction::execute(Mob* enemy, Player* player) {
    if (!enemy || !player) {
        return;
    }

    enemy->getDamaged(player->getHitPower());
}  