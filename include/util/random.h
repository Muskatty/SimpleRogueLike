#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <time.h>

class Random {
public:
    static void initialize();
    static unsigned int getRandomPercent();
    static unsigned int getRandomOneToN(unsigned int n);
private:
    Random() = default;
    static std::mt19937& engine();
};

#endif