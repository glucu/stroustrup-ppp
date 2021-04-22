#include "../include/std_lib_facilities.h"

// Program to convert miles to kilometers

int main() {

    const double kilometer = 1.609;

    std::cout << "Please enter a number of miles (followed by 'enter'):\n";
    double miles{};
    std::cin >> miles;

    if(miles == 1)
        std::cout << miles << " mile is " << (miles * kilometer) << " kilometers.\n";
    else
        std::cout << miles << " miles is " << (miles * kilometer) << " kilometers.\n";

    return 0; 
}