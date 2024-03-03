#pragma once
#include <iostream>

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;

    float to_float()
    {
        return 
        {
            static_cast<float>(numerator) / static_cast<float>(denominator)
        };
    }

    operator float() const
    {
        return static_cast<float>(numerator) / static_cast<float>(denominator);
    }

    Fraction& operator+=(Fraction const& f);

    Fraction& operator-=(Fraction const& f);

    Fraction& operator*=(Fraction const& f);

    Fraction& operator/=(Fraction const& f);
};

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& f);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);