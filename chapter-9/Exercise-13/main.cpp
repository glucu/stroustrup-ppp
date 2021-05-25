#include "Rational.h"
#include "std_lib_facilities.h"

int main() {

	try {

		Rational r1{ 5, 1 };
		Rational r2{ 7, 4 };
		Rational res{};

		// Addition
		res = r1 + r2;
		std::cout << r1 << " + " << r2 << " = " << res << '\n';

		r1.set_rational(4, 8);
		r2.set_rational(2, 4);

		// Substaction
		res = r1 - r2;
		std::cout << r1 << " - " << r2 << " = " << res << '\n';

		r1.set_rational(1, 2);
		r2.set_rational(3, 7);
		
		// Multiplication
		res = r1 * r2;
		std::cout << r1 << " * " << r2 << " = " << res << '\n';

		r1.set_rational(5, 1);
		r2.set_rational(4, 1);

		// Division
		res = r1 / r2;
		std::cout << r1 << " / " << r2 << " = " << res << '\n';

		// Comparison
		if (r1 == r2) {
			std::cout << "Same fractions\n";
		}
		else {
			std::cout << "Different fractions\n";
		}

		return 0;

	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "Exception: something went wrong\n";
		return 2;
	}
}