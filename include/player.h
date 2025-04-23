#ifndef PLAYER_H
#define PLAYER_H


#include "items/item.h"
#include "items/equipment.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>


class Player {
private:
    std::string name = "Player";
    int hp = 50;
    int maxHp = 50;

    unsigned int lvl = 1;
    unsigned int exp = 0;
    unsigned int upperExpBound = 60;

    unsigned int atk = 5;
    unsigned int healPower = 4;

    std::vector<std::unique_ptr<Item>> inventory;
    Equipment eq;
public:
    Player() {
        inventory.reserve(20);
    };
    Player(std::string _name) : name(_name) {
        inventory.reserve(20);
    };
    
    //Get damaged by x damage, if hp is above 0 return 0, else return -1
    int getDamaged(int damage);
    void heal();
    void earnExp(int exp);
    void increaseStat(std::string statName, int statBonus);
    void addItem(std::unique_ptr<Item> item);
    void equipItem(std::unique_ptr<Item> item);

    //this naming kinda sucks. calculate base atk + weapon atk
    unsigned int getHitPower() const;
    unsigned int getAtk() const {return atk;};
    unsigned int getHealPower() const {return healPower;};
    std::vector<Item*> getInventory() const;
    std::string getName() const {return name;};
    
    int getHp() const {return hp;};
    int getMaxHp() const {return maxHp;};

    unsigned int getLvl() const {return lvl;};
    unsigned int getExp() const {return exp;};
    unsigned int getExpBound() const {return upperExpBound;};
};

#endif