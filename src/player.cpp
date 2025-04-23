#include "player.h"
#include "cmath"

int Player::getDamaged(int damage) {
    this->hp -= damage; //TODO: add damage reduction mechanic
    if (this->hp <= 0) {
        return -1;
    }
    return 0;
}

void Player::heal() {
    this->hp += 4 * this->lvl; //TODO: add cool healing mechanic
    this->hp = std::min(hp, maxHp);
}

void Player::earnExp(int exp) { //TODO: balance stats progression
    this->exp += exp;
    if (this->exp >= this->upperExpBound) {
        this->lvl++;
        this->atk *= 1.3;
        this->maxHp *= 1.15;
        printf("Level up! Level %d\n", this->lvl);
        this->exp -= this->upperExpBound;
        this->upperExpBound = (int)pow(60.0, (pow(1.07, this->lvl - 1.0)));
    }
}

//TODO: make stat upgrades more interesting maybe
void Player::increaseStat(std::string statName, int statBonus) {
    if (statName == "ATK") {
        this->atk += statBonus;
    } else if (statName == "HP") {
        this->maxHp += statBonus;
    }
}

void Player::addItem(std::unique_ptr<Item> item) {
    this->inventory.push_back(std::move(item));
}

void Player::equipItem(std::unique_ptr<Item> item) {
    if (!item) {
        return;
    }

    EquipmentSlot slot = item->getSlot();
    
    std::unique_ptr<Item> prevItem = this->eq.equip(slot, std::move(item));

    if (prevItem) {
        this->addItem(std::move(prevItem));
    }
}

unsigned int Player::getHitPower() const {
    unsigned int res = this->getAtk();
    res += this->eq.getDamage();
    return res;
}

std::vector<Item*> Player::getInventory() const {
    std::vector<Item*> res;
    res.reserve(inventory.size());
    
    for (auto &ptr : inventory) {
        res.push_back(ptr.get());
    }

    return res;
}

Item* Player::getItem(EquipmentSlot slot) {
    return this->eq.getItem(slot);
}