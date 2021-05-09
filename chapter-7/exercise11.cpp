
/* Chapter 7: exercise 11
 *
 *  Revisit two programs you wrote for the exercises in Chapter 4 or 5.
 *	Clean up that code according to the rules outlined in this chapter. See if
 *	you find any bugs in the process.
 */

#include "../include/std_lib_facilities.h"


/* Chapter 4: exercise 5
 * 
 * COMMENT:
 * Although the arithmetic operators are obvious and I wouldn't consider them
 * as magic constants, I decided anyways to use enums (C++11) to clean up the look.
 * I also introduced a function called check() that gets called when the state of std::cin
 * fails, it will bring it back to a good state and asks the user to try again. In addition,
 * I put the logic inside of calculate() that way main is more clean. The restructure
 * of the program forces there to be no exceptions to be thrown (I lied, could've done it but it would have been ugly). 
 * But Stroustrup will consider it "suspicious" for sure. But did I really cover all errors?
 */

const std::string prompt{"> "};
const char quit{'q'};

enum Opers : const char {

	ADD = '+',
	SUBSTRACT = '-',
	MULTIPLY = '*',
	DIVIDE = '/'
};

void ignoreLine() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void check() {

	std::cin.clear();
	ignoreLine();
	std::cout << "Oops, that input is invalid. Please try again.\n";
}

void calculate() {

	double val1{}, val2{};

    char operation{' '};

	try {
		while(true) {

			std::cout << prompt;
			std::cin >> val1 >> operation >> val2;
			if(std::cin.fail()) check();
			else {

				ignoreLine();
				double result{};
				std::string text;
				switch(operation) {

				case ADD:
					text = "sum of ";
					result = val1 + val2;
					break;
				case SUBSTRACT:
					text = "difference between ";
					result = val1 - val2;
					break;
				case MULTIPLY:
					text = "product of ";
					result = val1 * val2;
					break;
				case DIVIDE:
					if(val2 == 0) {
						error("Division by zero!\n");
					}
					text = "ratio of ";
					result = val1 / val2;
					break;
				case quit:
					return;

				default:
					std::cout << "Not a operator I know, try again:\n";
					continue;  // I don't like it, but perhaps the user mis-typed
					           // Let's give him/her a chance again.
				}

				std::cout << text << val1 << " and " << val2 << " is " << result << "\n\n";
			}
		}
	}
	catch(const std::runtime_error &e) {
		std::cerr << e.what() << '\n';
	}
	catch(...) {
		std::cerr << "Exception: something went wrong\n";
	}
}

int main() {

    std::cout << "Please enter two operands followed by an operator \n"
              << "The operator can be '+', '-', '*', or '/':\n";

	calculate();
	return 0;
}