#include "player.h"
#include "cmath"

Player::Player(std::string _name) {
    this->name = _name;
}

int Player::get_damaged(int damage) {
    this->hp -= damage; //TODO: add damage reduction mechanic
    if (this->hp <= 0) {
        return -1;
    }
    return 0;
}

void Player::heal() {
    this->hp += 4 * this->lvl; //TODO: add cool healing mechanic
    this->hp = std::min(hp, max_hp);
}

void Player::earn_exp(int exp) { //TODO: balance stats progression
    this->exp += exp;
    if (this->exp >= this->upper_exp_bound) {
        this->lvl++;
        this->atk *= 1.3;
        this->max_hp *= 1.15;
        printf("Level up! Level %d\n", this->lvl);
        this->exp -= this->upper_exp_bound;
        this->upper_exp_bound = (int)pow(60.0, (pow(1.07, this->lvl - 1.0)));
    }
}
