#include "../include/std_lib_facilities.h"

int main() {

    const std::vector<std::string> spelled_digits{"zero", "one", "two", "three", "four", 
                                                  "five", "six", "seven", "eight", "nine"};
    const std::vector<std::string> digits{"0", "1", "2", "3", "4", 
                                          "5", "6", "7", "8", "9"};

    std::cout << "Please enter two single-digit numbers followed by an operator \n"
              << "The operator can be '+', '-', '*', or '/':\n";
    std::string str_val1,  str_val2;
    char operation{' '};
    while(std::cin >> str_val1 >> str_val2 >> operation) {

        int val1{}, val2{};
        std::string text;
        int result{};
        for(int i = 0; i < spelled_digits.size(); ++i) {

            if(spelled_digits[i] == str_val1 || digits[i] == str_val1) {
                val1 = i;
            }

            if(spelled_digits[i] == str_val2 || digits[i] == str_val2) {
                val2 = i;
            }
        }

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