#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter two integer values (followed by 'enter'):\n";
    int val1{}, val2{};
    std::cin >> val1 >> val2;

    int min = (val1 < val2) ? val1 : val2;  // ternary conditional operator
    int max = (val1 > val2) ? val1 : val2;  // equivalent to if(...) else ...
    int sum = val1 + val2;
    int diff = val1 - val2;
    int product = val1 * val2;
    int ratio = val1 / val2;

    std::cout << "min == " << min 
              << "\nmax == " << max
              << "\nsum == " << sum
              << "\ndiff == " << diff
              << "\nproduct == " << product
              << "\nratio == " << ratio
              << '\n';

    return 0;
}