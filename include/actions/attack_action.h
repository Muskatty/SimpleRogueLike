#include "actions/action.h"

class AttackAction: public Action {
public:
    AttackAction() {};
    ~AttackAction() {};

    void execute(Mob* enemy, Player* player) override;
};