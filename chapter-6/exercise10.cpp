#include "../include/std_lib_facilities.h"

/* Chapter 6: exercise 10
 *
 * A permutation is an ordered subset of a set. For example, say you wanted to
 * pick a combination to a vault. There are 60 possible numbers, and you need
 * three different numbers for the combination. There are P(60,3) permutations
 * for the combination, where P is defined by the formula
 * 
 *                a! 
 *     P(a,b) = ------,
 *              (a-b)!
 * 
 * where ! is used as a suffix factorial operator. For example, 4! is
 * 4*3*2*1.
 *  
 * Combinations are similar to permutations, except that the order of the
 * objects doesn't matter. For example, if you were making a "banana split"
 * sundea and wished to use three different flavors of ice cream out of five
 * that you had, you wouldn't care if you used a scoop of vanilla at the
 * beginning or the end; you would still have used vanilla. The formula for
 * combination is
 * 
 *              P(a,b)
 *     C(a,b) = ------.
 *                b!
 * 
 * Design a program that asks users for two numbers, asks them whether they
 * want to calculate permutations or combinations, and prints out the result.
 * This will have several parts. Do an analysis of the above requeriments.
 * Write exactly what the program will have to do. Then go into design phase.
 * Write pseudo code for the program, and break it into sub-components. This
 * program should have error checking. Make sure that all erroneous inputs will
 * generate good error messages
 */

const std::string factI_error1{"int factI(n): pre-condition violated"};
const std::string factI_error2{"int factI(n): pre-condition violated"};
const std::string permu_error("int permutations(a,b): pre-condition violated");
const std::string bad_input{"Bad input read"};

int factI(int n) {
// calculate factorial
// pre-condition: factorial of a negative number
//                is not defined or factorial got too large.

    if(n < 0) error(factI_error1);

    int result{1};
    while(n > 0) {
        result *= n;
        if( result < 1) error(factI_error2);
        --n;
    }

    return result;
}

int permutations(int a, int b) {
// calculate permutations
// pre-condition: n ≥ r ≥ 0

    if(a < b && b < 0) error(permu_error);

    return factI(a) / factI(a-b);
}

int combinations(int a, int b) {
// calculate combinations

    return permutations(a, b) / factI(b);
}

int solve_equad(int a, int b, char op) {

    int ans{};
    switch(op) {
    case 'p':
    case 'P': {
        ans = permutations(a, b);
        break;
    }
    case 'c':
    case 'C': {
        ans = combinations(a, b);
        break;
    }

    default:
        error(bad_input);
    }

    return ans;
}

void ignore_line() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {

    try {

        std::cout << "Please enter two numbers (followed by '|' to quit):\n";
        std::cout << ">> ";
        int a{}, b{};
        while(std::cin >> a >> b) {

            if(std::cin.fail()) {
                std::cin.clear();
                ignore_line();
                std::cout << "Numbers, please!\n";
                std::cout << ">> ";
            }
            else {

                std::cout << "Now, do you want to calculate permutations or combinations (p/c)?\n";
                char op{'?'};
                std::cin >> op;
                int ans{ solve_equad(a, b, op) };

                std::cout << "\nP(" << a << ',' << b << ") = " << ans << '\n';
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