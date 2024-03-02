#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 {3, 4};
    Fraction f2 {1, 2};
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    std::cout << "f1 + f2 = " << (f1+f2) << std::endl;
    std::cout << "f1 - f2 = " << (f1-f2) << std::endl;
    std::cout << "f1 * f2 = " << (f1*f2) << std::endl;
    std::cout << "f1 / f2 = " << (f1/f2) << std::endl;

    std::cout << "f1 == f2 : " << (f1==f2) << std::endl;
    std::cout << "f1 != f2 : " << (f1!=f2) << std::endl;

    std::cout << "f1 < f2 : " << (f1<f2) << std::endl;
    std::cout << "f1 <= f2 : " << (f1<=f2) << std::endl;
    std::cout << "f1 > f2 : " << (f1>f2) << std::endl;
    std::cout << "f1 >= f2 : " << (f1>=f2) << std::endl;

    std::cout << f1.to_float() << std::endl;;
    
    float d1 {static_cast<float>(f1)};
    std::cout << d1 << std::endl;

    return 0;
}