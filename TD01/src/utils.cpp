#include "utils.hpp"

unsigned int gcd(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int modulo {a % b};
        a = b;
        b = modulo;
    }

    return a;
}
// recursive version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }


Fraction simplify(Fraction const& f) {
    unsigned int divisor { gcd(f.numerator, f.denominator) };

    return {
        f.numerator / divisor,
        f.denominator / divisor
    };
}