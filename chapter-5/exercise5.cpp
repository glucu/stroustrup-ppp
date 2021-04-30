#include "../include/std_lib_facilities.h"

/* Chapter 5: exercise 5
 *
 * Add to the program so that it can also convert from Kelvin to Celsius.
 */

//class Abszero{};
//class Bad_input{};

constexpr double cel_abszero{ -273.15 };
constexpr double kel_abszero{ 0 };
constexpr double kelvin{ 273.15 };

const std::string bad_input_error{"int main(): couldn't read input"};
const std::string bad_temp_read{"pre-condition violation for temperature reading"};

double ctok(double c) {
// Converts Celsius to Kelvin
// pre-condition: parameter c cannot 
//                be below absolute zero

    if(c < cel_abszero) error(bad_temp_read);

    return c + kelvin;
}

double ktoc(double k) {
// Converts Kelvin to Celsius
// pre-condition: parameter k cannot 
//                be below absolute zero
    if(k < kel_abszero) error(bad_temp_read);

    return k - kelvin;
}

int main() {

    try {

        std::cout << "Would you like to enter a temperature in Celsius or Kelvin (c/k)?\n";
        char user_ans{' '};
        std::cin >> user_ans;
        
        double c{};
        double k{};

        switch(user_ans) {
        case 'c':
            std::cout << "\n>> ";
            std::cin >> c;
            if(std::cin) {
                k = ctok(c);
                std::cout << c << "C = " << k << "K\n";
            }
            else {
                error(bad_input_error);
            }
            break;
        
        case 'k':
            std::cout << "\n>> ";
            std::cin >> k;
            if(std::cin) {
                c = ktoc(k);
                std::cout << k << "K = " << c << "C\n";
            }
            else {
                error(bad_input_error);
            }
            break;

        default:
            error(bad_input_error);
            break;
        }
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