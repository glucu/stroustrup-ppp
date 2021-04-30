#include "../include/std_lib_facilities.h"

/* Chapter 5: exercise 3 
 *
 *  Absolute zero is the lowest temperature that can be reached; it is -273.l5°C,
 *  or OK. The above program, even when corrected, will produce erroneous results 
 *  when given a temperature bdow this. Place a check in the main program that will 
 *  produce an error if a temperature is given below -273.l5°C.
 */

/* COMMENT:
 * This is essentially the same as exercise 2; however, I have the error handling
 * done in the caller.
 */


// class Abszero{};
// class Bad_input{};

constexpr double kelvin{ 273.15 };

const std::string bad_input_error{"int main(): couldn't read a double value"};
const std::string bad_temp_read{"int main(): Impossible temperature returned"};

double ctok(double c) {
// Converts Celsius to Kelvin

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
        if(std::cin) {                          // std::cin state returns goodbit 

            double k = ctok(c);
            if(k < 0) {
                error(bad_temp_read);
            }
            else {
                std::cout << c << "C = " << k << "K\n";
            }
        }
        else if(std::cin.eof()) {               // end-of-file character (CTRL-Z) detected.
           std::cout << "Now exiting...\n";
        }
        else {                                  // Reaching here means std::cin failed. 
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