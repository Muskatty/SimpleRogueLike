#ifndef GOBLIN_H
#define GOBLIN_H

#include "mob.h"
#include <iostream>

class Goblin : public Mob {
public:
    Goblin() : Mob("Goblin", 20, 3) {}    
};

#endif