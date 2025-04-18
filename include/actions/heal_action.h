#include "actions/action.h"

class HealAction: public Action {
public:
    HealAction() {};
    ~HealAction() {};

    void execute(Mob *enemy, Player* player) override;
};