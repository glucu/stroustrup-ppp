#include "../../include/std_lib_facilities.h"

/* Drill 7:
 * Go back to 2 and cause your output to show the base for each output.
 */

void print(int birth_year) {
// prints birth_year in decimal, hexadecimal,
// and octal format.

    std::cout << std::showbase;
    std::cout << "(General format)\t" << birth_year << '\n'
              << "(Hexadecimal format)\t" << std::hex << birth_year << '\n'
              << "(octal format)\t\t" << std::oct << birth_year << '\n';
}

int main() {

    std::cout << "Please enter your birth year: ";
    int birth_year{};
    std::cin >> birth_year;

    print(birth_year);

    std::cout << "Now, enter your age: ";
    int age{};
    std::cin >> age;

    // std::cout << "age: " << age << '\n';   // Remember, std::oct still sticks, so it prints age in octal.
    std::cout << "age: " << std::dec << age << '\n';

    return 0;
}