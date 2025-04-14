#ifndef ACTION_FACTORY_H
#define ACTION_FACTORY_H

#include "actions/attack_action.h"
#include "actions/heal_action.h"

enum ActionType {
    ATTACK_ACTION = 1,
    HEAL_ACTION,
    INVALID_ACTION
};

class ActionFactory {
private:
    ActionFactory() {};
public:
    static std::unique_ptr<Action> createAction(ActionType type);
};

#endif