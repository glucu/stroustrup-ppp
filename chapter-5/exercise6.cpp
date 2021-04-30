#include "../include/std_lib_facilities.h"

/* Chapter 5: exercise 6 
 *
 * Write a program that converts from Celsius to Fahrenheit and from
 * Fahrenheit to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if
 * your results are plausible.
 */


//class Abszero{};

constexpr double cel_abszero{ -273.15 };
constexpr double fah_abszero{ -459.67 };

const std::string bad_input_error{"int main(): couldn't read input"};
const std::string bad_temp_read{"pre-condition violation for temperature reading"};

double ctof(double c) {
// Converts Celsius to Fahrenheit
// pre-condition: parameter c cannot be
//                below absolute zero.

    if(c < cel_abszero) {
        error(bad_temp_read);
    }

    double f{ 9.0 / 5.0 * c + 32 };
    return f;
}

double ftoc(double f) {
// Converts Fahrenheit to Celsius
// pre-condition: parameter f cannot be
//                below absolute zero.

    if(f < fah_abszero) {
        error(bad_temp_read);
    }

    double c{ (f - 32) * 5.0 / 9.0 };
    return c;
}

int main() {

    try {

        std::cout << "Please enter a temperature in Celsius or Fahrenheit followed by the unit to convert to.\n";
        std::cout << "Unit: c, f, or q to quit:\n\n";
        std::cout << ">> ";
        double deg{};
        char unit{' '};
        while(std::cin >> deg >> unit && unit != 'q') {

            if(std::cin) {

                switch(unit) {
                case 'c':
                    std::cout << deg << "C = " << ctof(deg) << "F\n";
                    break; 
                case 'f':
                    std::cout << deg << "F = " << ftoc(deg) << "C\n";
                    break;
                default:
                    std::cout << "Not a unit I know, Try again:\n";
                    break;
                }
            }
            else if(std::cin.eof()) {
                std::cout << "Now exiting...\n";
            }
            else {
                std::cout << "Error, couldn't read a double. Try again:\n";
            }

            std::cout << "\n>> ";
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