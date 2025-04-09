#ifndef ORC_H
#define ORC_H

#include "mob.h"
#include <iostream>

class Orc : public Mob {
public:
    Orc() : Mob("Orc", 35, 6) {}    
};

#endif