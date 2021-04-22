#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "How many pennies do you have? ";
    int pennies{};
    std::cin >> pennies;

    std::cout << "How many nickels do you have? ";
    int nickels{};
    std::cin >> nickels;

    std::cout << "How many dimes do you have? ";
    int dimes{};
    std::cin >> dimes;

    std::cout << "How many quarters do you have? ";
    int quarters{};
    std::cin >> quarters;

    std::cout << "How many half dollars do you have? ";
    int half_dollars{};
    std::cin >> half_dollars;

    std::cout << "How many dollars do you have? ";
    int dollars{};
    std::cin >> dollars;

    std::cout << '\n';

    if(pennies > 0) {
        std::cout << "You have " << pennies;
        if(pennies == 1)
            std::cout << " penny.\n";
        else
            std::cout << " pennies.\n";
    }

    if(nickels > 0) {
        std::cout << "You have " << nickels;
        if(nickels == 1)
            std::cout << " nickel.\n";
        else
            std::cout << " nickels.\n";
    }

    if(dimes > 0) {
        std::cout << "You have " << dimes;
        if(dimes == 1)
            std::cout << " dime.\n";
        else
            std::cout << " dimes.\n";
    }

    if(quarters > 0) {
        std::cout << "You have " << quarters;
        if(quarters == 1)
            std::cout << " quarter.\n";
        else
            std::cout << " quarters.\n";
    }

    if(half_dollars > 0) {
        std::cout << "You have " << half_dollars;
        if(half_dollars == 1)
            std::cout << " half dollar.\n";
        else
            std::cout << " half dollars.\n";
    }

    if(dollars > 0) {
        std::cout << "You have " << dollars;
        if(dollars == 1)
            std::cout << " dollar.\n";
        else
            std::cout << " dollars.\n";
    }

    double  total = (pennies * 1) + (nickels * 5) + (dimes * 10) + (quarters * 25) + (half_dollars * 50) + (dollars * 100);
    double sum = total / 100;
    std::cout << "The value of all of your coins is $" << sum << '\n';

    return 0;
}