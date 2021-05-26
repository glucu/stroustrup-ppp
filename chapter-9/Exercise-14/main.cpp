#include "Money.h"

int main() {

	try {

		Money m1{ 4, 65 };
		Money m2{ 2, 20 };

		// print out the currency
		std::cout << m1 << '\n';
		std::cout << m2 << '\n';

		std::cout << m1 << " + " << m2 << " = " << (m1 + m2) << '\n';
		std::cout << m1 << " - " << m2 << " = " << (m1 - m2) << '\n';
		
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