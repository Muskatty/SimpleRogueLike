#ifndef TROLL_H
#define TROLL_H

#include "mob.h"
#include <iostream>

class Troll : public Mob {
public:
    Troll() : Mob("Troll", 50, 8) {}    
};

#endif