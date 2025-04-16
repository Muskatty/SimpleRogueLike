#include "items/item_factory.h"
#include "util/random.h"

std::unique_ptr<Item> ItemFactory::createRandomItem(int lvl) {
    //lvl not used yet
    int percent = Random::getRandomPercent();
    
    if (percent <= 100) {
        return WeaponFactory::createRandomWeapon();
    } else {

    }
}