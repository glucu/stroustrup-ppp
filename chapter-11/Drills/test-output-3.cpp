#include "../../include/std_lib_facilities.h"

/* Drill 3:
 * Label each value with the name of the base used. 
 */

void print(int birth_year) {
// prints birth_year in decimal, hexadecimal,
// and octal format.

    std::cout << "(General format)\t" << birth_year << '\n'
              << "(Hexadecimal format)\t" << std::hex << birth_year << '\n'
              << "(octal format)\t\t" << std::oct << birth_year << '\n';
}

int main() {

    std::cout << "Please enter your birth year: ";
    int birth_year{};
    std::cin >> birth_year;

    print(birth_year);

    return 0;
}