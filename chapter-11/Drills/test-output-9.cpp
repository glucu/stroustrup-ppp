#include "../../include/std_lib_facilities.h"

/* Drill 9:
 *
 * Write some code to print the number 1234567.89 three times, first using
 * defaultfloat, then fixed, then scientific forms. Which output form presents
 * the user with the most accurate representation? Explain why. 
 */

/* COMMENT:
 * fixed seems to present the number more accurately.
 */

int main() {

    double val{1234567.89};

    std::cout << "defaultfloat format: " << val << '\n';
    std::cout << "fixed format: " << std::fixed << val << '\n';
    std::cout << "scientific format: " << std::scientific << val << '\n';

    return 0;
}