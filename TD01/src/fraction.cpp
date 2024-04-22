#include "fraction.hpp"
#include "utils.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f) 
{
    return os << f.numerator << "/" << f.denominator;
}

// Fraction operator+(Fraction const& f1, Fraction const& f2) 
// {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator-(Fraction const& f1, Fraction const& f2) 
// {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) 
// {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) 
// {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }

bool operator==(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator==f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator!=f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator < f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator <= f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator > f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(Fraction & f1, Fraction & f2)
{
    simplify(f1);
    simplify(f2);

    if (f1.numerator*f2.denominator >= f2.numerator*f1.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Fraction& Fraction::operator+=(Fraction const& f) 
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f) 
{
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f) 
{
    numerator = f.numerator * numerator;
    denominator = denominator * f.denominator;
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f) 
{
    numerator = f.numerator * denominator;
    denominator = numerator * f.denominator;
    return *this;
}

Fraction operator+(Fraction f1, Fraction const& f2) 
{
    f1+=f2;
    return simplify(
        f1
    );
}

Fraction operator-(Fraction f1, Fraction const& f2) 
{
    f1-=f2;
    return simplify(
        f1
    );
}

Fraction operator*(Fraction f1, Fraction const& f2) 
{
    f1*=f2;
    return simplify(
        f1
    );
}

Fraction operator/(Fraction f1, Fraction const& f2) 
{
    f1/=f2;
    return simplify(
        f1
    );
}