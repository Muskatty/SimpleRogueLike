#ifndef HEAL_ACTION_H
#define HEAL_ACTION_H

#include "actions/action.h"

class HealAction: public Action {
public:
    HealAction() {};
    ~HealAction() {};

    void execute(Mob *enemy, Player* player) override;
};

#endif