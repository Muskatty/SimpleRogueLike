#include "util/random.h"

void Random::initialize() {
    engine().seed(std::random_device{}());
}

unsigned int Random::getRandomPercent() {
    return getRandomOneToN(100);
}

unsigned int Random::getRandomOneToN(unsigned int n) {
    std::uniform_int_distribution<uint32_t> uintN(1, n);
    return uintN(engine());
}

std::mt19937& Random::engine() {
    static std::mt19937 rng(time(NULL));
    return rng;
}