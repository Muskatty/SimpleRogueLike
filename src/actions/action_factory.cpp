#include "actions/action_factory.h"

std::unique_ptr<Action> ActionFactory::createAction(ActionType type) {
    switch (type)
    {
    case ATTACK_ACTION:
        return std::make_unique<AttackAction>();
    case HEAL_ACTION:
        return std::make_unique<HealAction>();
    default:
        return nullptr;
    }
}