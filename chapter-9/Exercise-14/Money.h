#ifndef MONEY_H
#define MONEY_H

#include "std_lib_facilities.h"

constexpr char unit{ '$' };
long int my_round(double d);

class Money {
public:
    Money();   // defaults to 0
    explicit Money(long int c);
    Money(int d, int c);

    // getters
    int get_dollars() const { return m_money / 100; }
    int get_cents() const { return m_money % 100; }
    int get_amount() const { return m_money;  }

    // operator overloading for Money class
    friend Money operator+(const Money& lhs, const Money& rhs);
    friend Money operator-(const Money& lhs, const Money& rhs);
    friend Money operator*(const Money& lhs, double rhs);
    friend Money operator*(double lhs, const Money& rhs);
    friend Money operator/(const Money& lhs, double rhs);
    friend double operator/(const Money& lhs, const Money& rhs);

    friend bool operator==(const Money& lhs, const Money& rhs);
    friend bool operator!=(const Money& lhs, const Money& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Money& r);

private:
    long m_money;
};

#endif // !MONEY_H