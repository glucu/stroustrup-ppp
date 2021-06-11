#include "../../include/std_lib_facilities.h"

/* Drill 8:
 * Try reading as octal, hexadecimal, etc.:
 *
 * cin >> a >> oct >> b >> hex >> c >> d;
 * cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
 * Run this code with the input 
 * 1234 1234 1234 1234
 * Explain the results. 
 */

/* COMMENT:
 * a prints in decimal, b in octal, and both c/d in hexadecimal because
 * std::hex sticks.
 */

int main() {

    int a{}, b{}, c{}, d{};
    std::cin >> a >> std::oct >> b >> std::hex >> c >> d;

    std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    return 0;
}