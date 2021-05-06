#include "../include/std_lib_facilities.h"

/* COMMENT:
 * On Windows 10 Visual Studio Code, if I read in whole numbers,
 * I get the same results (integers) like in the previous exercise.
 * Except that for ratio, I get a decimal value where the result is not
 * truncated. 
 */

int main() {

    std::cout << "Please enter two floating-point numbers (followed by 'enter'):\n";
    double val1{}, val2{};
    std::cin >> val1 >> val2;

    double min = (val1 < val2) ? val1 : val2;  // ternary conditional operator
    double max = (val1 > val2) ? val1 : val2;  // equivalent to if(...) else ...
    double sum = val1 + val2;
    double diff = val1 - val2;
    double product = val1 * val2;
    double ratio = val1 / val2;

    std::cout << "min == " << min 
              << "\nmax == " << max
              << "\nsum == " << sum
              << "\ndiff == " << diff
              << "\nproduct == " << product
              << "\nratio == " << ratio
              << '\n';

    return 0;
}