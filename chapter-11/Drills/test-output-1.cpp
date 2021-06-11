#include "../../include/std_lib_facilities.h"

/* Drill 1:
 *
 * Start a program called Test_output.cpp. Declare an integer birth_year
 * and assign it the year you were born. 
 */

int main() {

    std::cout << "Please enter your birth year: ";
    int birth_year{};
    std::cin >> birth_year;

    std::cout << "birth year: " << birth_year << '\n';

    return 0;
}