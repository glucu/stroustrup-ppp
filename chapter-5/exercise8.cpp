#include "../include/std_lib_facilities.h"

/* Chapter 5: exercise 8  
 *
 *  Write a program that reads and stores a series of integers and then computes
 *  the sum of the first N integers. First ask for N, then read the values into
 *  a vector, then calculate the sum of the first N values. For example:
 *
 *  "Please enter the number of values you want to sum:"
 *
 *      3
 *
 *  "Please enter some integers (press '|' to stop):"
 *
 *      12 23 13 24 15 |
 *
 *  "The sum of the first 3 numbers ( 12 23 13 ) is 48."
 *
 *  Handle all inputs. For example, make sure to give an error message if the
 *  user asks for a sum of more numbers than there are in the vector.
 */

/*  COMMENT:
 *  This problem got me thinking of using strings to hold
 *  error messages, and to pass each one to a particular
 *  call to throw.
*/

const std::string sum_of_N_error{"Number of values you want to sum exceeds size of vector"};
const std::string bad_input_error{"sum of more numbers than there are in the vector"};
constexpr char quit{'|'};

int sum_of_N(const std::vector<int> &elements, const int N) {
// Returns the sum of the first N elements
// pre-condition: elements must have at least
//                N elements

    if(N > elements.size()) throw std::runtime_error{sum_of_N_error};

    int sum{};
    for(int i{}; i < N; ++i) {
        sum += elements[i];
    }

    return sum;
}

void ignore_line() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void read_values(std::vector<int> &elements) {
// Read in a series of integers into the vector.

    while(true) {

        std::cout << ">> ";
        int element{};
        std::cin >> element;

        if(!std::cin) {
            std::cin.clear();

            std::cout << ">> ";
            char q{' '};
            std::cin >> q;

            if(q == quit) break;
            else {
                std::cin.clear();
                ignore_line();
                std::cout << "Not an integer or '|' to quit. Try again:\n";
            }
        }
        else {
            ignore_line();
            elements.push_back(element);
        }
    }
}

int read_N() {
// Read in a value that you want to sum up to.

    while(true) {

        std::cout << ">> ";
        int N{};
        std::cin >> N;

        if(!std::cin) {
            std::cin.clear(); // Put us back in normal operation mode
            ignore_line();    // Removes bad input
            std::cout << "Couldn't read an integer. Try again:\n";
        }
        else {

            if(N < 1) {
                std::cout << "Sorry, please enter a number greater than zero:\n";
            }
            else {
                return N;
            }
        }
    }
}

bool is_valid(const std::vector<int> &elements, int N) {
// Returns true if N is greater than size of vector
// or N less than 1. Otherwise return false;
// pre-condition: N must be greater than size of vector
//                or greater than 1 

    if(N > elements.size() || N < 1) return true;

    return false;
}

int main() {

    try {

        std::cout << "Please enter the number of values you want to sum:\n\n";
        int N{ read_N() };

        std::cout << "\nPlease enter some integers (press '|' to stop):\n";
        std::vector<int> elements;
        read_values(elements);

        if(!is_valid(elements, N)) {

            std::cout << "The sum of the first " << N << " numbers ( ";
            for(int i{}; i < N; ++i) {
                std::cout << elements[i] << ' ';
            }
            std::cout << ") is " << sum_of_N(elements, N) << ".\n";
        }
        else {
            throw std::runtime_error{bad_input_error};
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