#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter two operands followed by an operator \n"
              << "The operator can be '+', '-', '*', or '/':\n";
    double val1{}, val2{};
    char operation{' '};
    while(std::cin >> val1 >> val2 >> operation) {

        double result{};
        std::string text;
        switch(operation) {

        case '+':
            text = "sum of ";
            result = val1 + val2;
            break;
        case '-':
            text = "difference between ";
            result = val1 - val2;
            break;
        case '*':
            text = "product of ";
            result = val1 * val2;
            break;
        case '/':
            if(val2 == 0)
                error("Division by zero.");
            text = "ratio of ";
            result = val1 / val2;
            break;
        default:
            error("I don't know that operator.");
            break;
        }

        std::cout << text << val1 << " and " << val2 << " is " << result << '\n';
    }

    return 0;
}