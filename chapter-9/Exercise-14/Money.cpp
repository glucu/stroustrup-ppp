#include "Money.h"

Money::Money()
    : m_money{ 0 } { }

Money::Money(long int c)
    : m_money{ c } { }

Money::Money(int d, int c)
    : m_money{ d * 100 + c }
{
    if (c >= 100) error("Money(): cent must be between 0-99");
}

long int my_round(double d) {

    return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

Money operator+(const Money& lhs, const Money& rhs) {

    return Money{ lhs.get_amount() + rhs.get_amount() };
}

Money operator-(const Money &lhs, const Money &rhs) {

    return Money{ lhs.get_amount() - rhs.get_amount() };
}

Money operator*(const Money& lhs, double rhs) {

    return Money{ my_round(lhs.get_amount() * rhs) };
}

Money operator*(double lhs, const Money& rhs) {

    return Money{ my_round(lhs * rhs.get_amount()) };
}

Money operator/(const Money& lhs, double rhs) {

    if (rhs == 0) error("operator/: Divide by zero");

    return Money{ my_round(lhs.get_amount() / rhs) };
}

double operator/(const Money& lhs, const Money& rhs) {

    if (rhs.get_amount() == 0) error("operator/: Divide by zero");

    return (double(lhs.get_amount()) / rhs.get_amount());
}

bool operator==(const Money &lhs, const Money &rhs) {

    return (lhs.get_amount() == rhs.get_amount());
}

bool operator!=(const Money &lhs, const Money &rhs) {

    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Money& m) {

    os << unit << m.get_dollars() << '.';
    if (abs(m.get_cents()) < 10) os << '0';    
    os << abs(m.get_cents());

    return os;
}