#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter an operator ('plus', 'minus', 'mul', or 'div'):\n";
    std::string operation;
    std::cin >> operation;

    std::cout << "Now enter two operands:\n";
    double val1{}, val2{};
    std::cin >> val1 >> val2;

    if(operation == "plus") {
        std::cout << "The sum of " << val1 << " and " << val2 << " is " << (val1 + val2) << '\n';
    }
    else if(operation == "minus") {
        std::cout << "The difference of " << val1 << " and " << val2 << " is " << (val1 - val2) << '\n';
    }
    else if(operation == "mul") {
        std::cout << "The product of " << val1 << " and " << val2 << " is " << (val1 * val2) << '\n';
    }
    else if(operation == "div") {
        std::cout << "The ratio of " << val1 << " and " << val2 << " is " << (val1 / val2) << '\n';
    }
    else {
        std::cout << operation << " is not a valid operator, sorry!\n";
    }

    return 0;
}