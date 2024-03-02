#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f) 
{
    return os << f.numerator << "/" << f.denominator;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) 
{
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator-(Fraction const& f1, Fraction const& f2) 
{
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) 
{
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) 
{
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

bool operator==(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator==f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator!=f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator<f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator<=f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator>f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(Fraction const& f1, Fraction const& f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator>=f2.numerator)
    {
        return true;
    }
    else
    {
        return false;
    }
}