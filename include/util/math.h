#ifndef MATH_H
#define MATH_H

class Math {
public:
    static int roundToInt(double d) {
        return (int)(d + 0.5);
    }

    static unsigned int roundToUint(double d) {
        int tmp = roundToInt(d);
        return tmp < 0 ? 0 : static_cast<unsigned int>(tmp);
    }
};

#endif