#include "../../include/std_lib_facilities.h"

/* Drill 2:
 *
 * Output your birth_year in decimal, hexadecimal, and octal form.
 */

void print(int birth_year) {
// prints birth_year in decimal, hexadecimal,
// and octal format.

    std::cout << birth_year << '\t' << std::hex << birth_year
              << '\t' << std::oct << birth_year << '\n';
}

int main() {

    std::cout << "Please enter your birth year: ";
    int birth_year{};
    std::cin >> birth_year;

    print(birth_year);

    return 0;
}