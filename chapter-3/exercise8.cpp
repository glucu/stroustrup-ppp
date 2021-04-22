#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter an integer value and I will tell you "
              << "if it's odd or even (followed by 'enter'):\n";

    int val{};
    std::cin >> val;

    if(val % 2 == 0) {
        std::cout << "The value " << val << " is an even number.\n";
    }
    else {
        std::cout << "The value " << val << " is an odd number.\n";
    }

    return 0;
}