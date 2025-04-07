#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
public:
    ~Item() {};
    Item(std::string _name) : name(_name) {};

    std::string getName() const {return name;};
};


#endif