#include "../include/std_lib_facilities.h"

int main() {

    const std::string zero = "zero";
    const std::string one = "one";
    const std::string two = "two";
    const std::string three = "three";
    const std::string four = "four";

    std::cout << "Please enter a spelled-out number ('zero', 'one', 'two', 'three', or 'four'):\n";
    std::string number;
    while(std::cin >> number) {
        if(number == zero) {
            std::cout << 0 << '\n';
        }
        else if(number == one) {
            std::cout << 1 << '\n';
        }
        else if(number == two) {
            std::cout << 2 << '\n';
        }
        else if(number == three) {
            std::cout << 3 << '\n';
        }
        else if(number == four) {
            std::cout << 4 << '\n';
        }
        else {
            std::cout << "Not a number I know, try again!\n";
        }
    }

    return 0;
}