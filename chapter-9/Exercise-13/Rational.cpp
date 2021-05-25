#include "Rational.h"
Rational::Rational()
	: m_num{1}, m_den{2} { }

Rational::Rational(int num, int den)
	: m_num{ num }, m_den{ den }
{
	if (check_den(den)) error("Rational::check_den(): divide by zero");
}

void Rational::set_rational(int num, int den) {

	if (check_den(den)) error("Rational::set_rational(): divide by zero" );

	m_num = num;
	m_den = den;
}

int Rational::gcd(int m, int n) {
	
	if (n == 0) return m;
	int r{ m % n };
	return gcd(n, r);
}

void Rational::simplify() {

	int res{ gcd(m_num, m_den) };

	m_num /= res;
	m_den /= res;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	
	Rational result{ (lhs.get_num() * rhs.get_den()) + (lhs.get_den() * rhs.get_num()), (lhs.get_den() * rhs.get_den()) };
	result.simplify();
	return result;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {

	Rational result{ (lhs.get_num() * rhs.get_den()) - (lhs.get_den() * rhs.get_num()), (lhs.get_den() * rhs.get_den()) };
	result.simplify();
	return result;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {

	Rational result{ (lhs.get_num() * rhs.get_num()), (lhs.get_den() * rhs.get_den()) };
	result.simplify();
	return result;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {

	if (rhs.get_den() == 0) error("operator/: divide by zero");

	Rational result{ (lhs.get_num() * rhs.get_den()), (lhs.get_den() * rhs.get_num()) };
	result.simplify();
	return result;
}

bool operator==(const Rational &lhs, const Rational &rhs) {

	return (lhs.get_num() == rhs.get_num() &&
		    lhs.get_den() == rhs.get_den());
}

bool operator!=(const Rational &lhs, const Rational &rhs) {

	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &os, const Rational &r) {

	os << r.get_num() << '/' << r.get_den();
	return os;
}