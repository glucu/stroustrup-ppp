#include "Rational.hpp"

Rational::Rational(int a, int b)
    : m_a_{a}, m_b_{b}
{
    if(b == 0) error("Rational::Rational: divide by zero is undefined!");
    if(b < 0) { // normalize the fraction
        m_b_ = -m_b_;
        m_a_ = -m_a_;
    }
    int div = gcd(m_a_, m_b_);
    m_a_ /= div;
    m_b_ /= div;
}

double Rational::float_conversion(Rational r) 
// convert the fraction into a floating-point
{
    return double(r.num()) / r.den(); 
}

int Rational::gcd(int a, int b)
// returns the greatest common divisor
// of the integers a and b
{
    return std::gcd(a,b);
}

// helper functions:
Rational operator+(Rational lhs, Rational rhs)
{
    return {lhs.num() * rhs.den() + lhs.den() * rhs.num(), lhs.den() * rhs.den()};
}

Rational operator-(Rational lhs, Rational rhs)
{
    return {lhs.num() * rhs.den() - lhs.den() * rhs.num(), lhs.den() * rhs.den()};
}

Rational operator*(Rational lhs, Rational rhs)
{
    return {lhs.num() * rhs.num(), lhs.den() * rhs.den()};
}

Rational operator/(Rational lhs, Rational rhs)
{
    return {lhs.num() * rhs.den(), lhs.den() * rhs.num()};
}

bool operator==(Rational lhs, Rational rhs)
{
    return lhs.num() == rhs.num() &&
           lhs.den() == rhs.den();
}

bool operator!=(Rational lhs, Rational rhs)
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream& os, Rational r)
{
    return os << r.num() << '/' << r.den();
}

istream& operator>>(istream &in, Rational &r)
{
    int a{}, b{};
    char ch{};
    in >> a >> ch >> b;
    if(!in) return in;

    if(ch != '/') {
        cin.clear(ios_base::failbit);
        return in;
    }

    r = Rational{a,b};
    return in;
}
