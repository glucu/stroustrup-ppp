#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <numeric> // for std::gcd()

#include "std_lib_facilities.h"

/*
 * COMMENT
 * Recap: A rational number is a number that can be represented as a fraction of two integers, a/b, where
 * a is the numerator and b is the denominator. b cannot be zero. Examples: 1/2, 3/7, -5/1 etc.
 * Examples of irrational numbers (cannot be represented as a rational number): pi, e, sqrt(2) etc.
 * All Rational numbers are real numbers (both rational and irrational numbers).
 *
 * I did a bit of cheating and went ahead and used the <b>std::gcd()</b> function defined in the <numeric>
 * header file to compute the greatest common divisor of the two numbers. This is a C++17 feature, so
 * make sure you compile with the <b>-std=c++17</b> flag. At first, I was writing the class declaration
 * in one file where the main() function was defined. I decided to move it in a Rational header file for
 * modularity.
 *
 * Note: Also, you may wonder why the Rational objects aren't being passed by <b>const-reference</b> but rather
 * by value. This is because the Rational class only has two data members of buil-in types (ints that are 4 bytes) * So the whole class is 8 bytes and passing 8 bytes by value (making a copy) shouldn't be a problem. That is
 * like passing a single double object as an argument to a function! 
 *
 * Lastly, as for the naming conventions for the data members. <b>m_</b> is a prefix that means that the variable
 * is a MEMBER variable. The trailing <b>_</b> suffix means member variable but it is private.
 *
 * Why would people want to use a Rational class?
 * I think people who are mathematicians would benefit from using the Rational class
 */

class Rational {
public:
    Rational(int a = 0, int b = 1);

    //non-modifying operations:
    int num() const { return m_a_; }
    int den() const { return m_b_; }

public:
    static double float_conversion(Rational r);

private:
    int gcd(int a, int b);

private:
    int m_a_;
    int m_b_;
};

// helper functions:
Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);
bool operator==(Rational lhs, Rational rhs);
bool operator!=(Rational lhs, Rational rhs);
ostream& operator<<(ostream& os, Rational r);
istream& operator>>(istream &in, Rational &r);
#endif
