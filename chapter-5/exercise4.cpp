#include "../include/std_lib_facilities.h"

/* Chapter 5: exercise 4
 *
 * Do exercise 3 again, but this time handle the error inside ctok()
 */

/* COMMENT:
 * The same as the previous exercise except we are adding the check
 * as a pre-condition in function ctok.
 */

//class Abszero{};
//class Bad_input{};

constexpr double kelvin{ 273.15 };
constexpr double abszero{ -273.15 };

const std::string bad_input_error{"int main(): couldn't read a double value"};
const std::string bad_temp_read{"ctok(c): pre-condition violation"};

double ctok(double c) {
// Converts Celsius to kelvin
// pre-condition: parameter c cannot be below absolute zero.

    if(c < abszero) error(bad_temp_read);

    return c + kelvin;
}

int main() {

    try {

        std::cout << "Celsius to Kelvin conversion\n";
        std::cout << "****************************\n\n";
        std::cout << "Please enter a temperature in Celsius (followed by 'enter'):\n";
        std::cout << ">> ";
        double c{};
        std::cin >> c;
        if(std::cin) {

            double k = ctok(c);
            std::cout << c << "C = " << k << "K\n";
    
        }
        else if(std::cin.eof()) {
            std::cout << "Now exiting...\n";
        }
        else {
            error(bad_input_error);
        }

        return 0;
    }
    catch(const std::runtime_error &e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong.\n";
        return 2;
    }
}