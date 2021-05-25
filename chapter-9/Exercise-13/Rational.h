#ifndef RATIONAL_H
#define RATIONAL_H

/* Chapter 9: exercise 13
 *
 * Design and implement a rational number class, Rational. A rational
 * number has two parts: a numerator and a denominator, for example, 5/6
 * (five-sixths, also known as approximately .83333). Look up the definition
 * if you need to. Provide assignment, addition, subtraction, multiplication, division,
 * and equality operators. Also, provide a conversion to double. Why would people want to use a Rational class?
 */

#include "std_lib_facilities.h"

class Rational {
public:
	Rational();   // defaults to 1/2
	// The explicit keyword ensures that it can only be used when the destination type is explicit at the point of use, e.g., with a cast.
	explicit Rational(int num, int den);

	// getters
	int get_num() const { return m_num; }
	int get_den() const { return m_den; }

	// setters
	void set_rational(int num, int den);
	double conversion_to_double() { return double(m_num) / m_den; }

	// operator overloading for Rational class
	friend Rational operator+(const Rational &lhs, const Rational &rhs);
	friend Rational operator-(const Rational &lhs, const Rational &rhs);
	friend Rational operator*(const Rational &lhs, const Rational &rhs);
	friend Rational operator/(const Rational &lhs, const Rational &rhs);

	friend bool operator==(const Rational &lhs, const Rational &rhs); 
	friend bool operator!=(const Rational &lhs, const Rational &rhs);

	friend std::ostream& operator<<(std::ostream &os, const Rational &r);

private:
	int m_num;   // numerator
	int m_den;   // denominator

	bool check_den(int den) const { return den == 0;  }   // check to prevent a divide by zero error

	int gcd(int m, int n);   // Euclid's algorithm
	void simplify();
};

#endif // !RATIONAL_H
