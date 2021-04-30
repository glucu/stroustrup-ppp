#include "../include/std_lib_facilities.h"

/*  Chapter 5: exercise 2
 *
 *  The following program takes in a temperature value in Celsius and converts
 *  it to Kelvin. This code has many errors in it. Find the errors, list them, 
 *  and correct the code
 */

/*
double ctok(double c) {     // converts Celsius to Kelvin

    int k = c + 273.15;
    return int
}

int main() {

    double c = 0;
    cin >> d;
    double k = ctok("c");
    Cout << k << '/n';
} 
*/


// In double ctok(double c) function:
// 1. The result of the expression: c + 273.15 is a floating-point result
//    which then gets truncated (unsafe conversion) to an int. Type should be double.
//
// 2. The return statement returns a type instead of the variable k. Also missing semicolon.

// In main() function:
// 1. reading into an undeclared variable d. Should be variable c
// 2. string literal is passed as an argument to ctok instead of
//    variable c.
// 3. Cout is not correctly written. Should be: cout << k << '\n;

// Additional concerns:
// 1. Checking the state of cin is not checked. What if the user
//    enters something other than a floating-point number?
// 2. Even if we do check cin, nothing is stopping the user
//    in entering a temperature that exceeds what is a possible
//    temperature. 
// 3. The program doesn't present itself well... The user has
//    no idea what this program even is!!

// Symbolic constants for not so obvious values
constexpr double min_temp{ -273.15 };    // Absolute zero in Celsius 
constexpr double max_temp{ 5500 };       // The sun's photosphere in Celsius
constexpr double kelvin{ 273.15 };       // To avoid magic constants

const std::string bad_temp_read{"ctok(double c): pre-condition violated"};
const std::string bad_input_error("int main(): couldn't read a double value");

double ctok(double c) { 
// Converts Celsius to Kelvin.
// pre-condition: Parameter c must not be below min_temp
// or above max_temp.

    if(c < min_temp || c > max_temp)
        error(bad_temp_read);
    
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