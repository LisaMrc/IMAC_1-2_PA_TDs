#include "utils.hpp"

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int modulo {a % b};
        a = b;
        b = modulo;
    }

    return a;
}

Fraction simplify(Fraction const& f) 
{
    unsigned int divisor { gcd(f.numerator, f.denominator) };

    return {
        f.numerator / divisor,
        f.denominator / divisor
    };
}