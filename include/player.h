#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <unordered_map>
#include <vector>


class Player {
private:
    std::string name = "Player";
    int hp = 50;
    int max_hp = 50;
    unsigned int lvl = 1;
    unsigned int exp = 0;
    unsigned int upper_exp_bound = 60;
    unsigned int atk = 5;
public:
    Player() {};
    Player(std::string _name);
    
    //Get damaged by x damage, if hp is above 0 return 0, else return -1
    int get_damaged(int damage);
    void heal();
    void earn_exp(int exp);

    unsigned int get_atk() {return atk;};
    std::string get_name() {return name;};
    int get_hp() {return hp;};
    int get_max_hp() {return max_hp;};
    unsigned int get_lvl() {return lvl;};
    unsigned int get_exp() {return exp;};
    unsigned int get_exp_bound() {return upper_exp_bound;};
};

#endif