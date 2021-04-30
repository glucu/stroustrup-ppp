#include "../include/std_lib_facilities.h"

/*   Chapter 5: exercise 10
 *
 *   Modify the program from exercise 8 to use double instead of int. Also,
 *   make a vector of doubles containing the N-1 diff_of_N between adjacent 
 *   values and write out that vector.
 */

const std::string sum_of_N_error{"number of values you want to sum exceeds size of vector"};
const std::string bad_input_error{"sum of more numbers than there are in the vector"};
const std::string no_diff_error{"can't calculate difference with less than two elements"};
constexpr char quit{'|'};

double sum_of_N(const std::vector<double> &elements, const int N) {
// Returns the sum of the first N elements
// pre-condition: elements must have at least
//                N elements

    if(N > elements.size()) throw std::runtime_error{sum_of_N_error};
    
    double sum{};
    for(int i{}; i < N; ++i) {
        sum += elements[i];
    }

    return sum;
}

void diff_of_N(std::vector<double> &diff, const std::vector<double> &elements, const int N) {
// For diff to contain the N-1 differences between the first
// N adjacent values in elements.
// pre-condition: elements must have at least N elements
//                N must be equal or greater than 2 for the differences

    if(N < 2) throw std::runtime_error{no_diff_error};
    if(N > elements.size()) throw std::runtime_error{sum_of_N_error};

    for(int i{}; i < N-1; ++i) {
        diff.push_back(std::abs(elements[i] - elements[i+1]));
    }
}

void ignore_line() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void read_values(std::vector<double> &elements) {
// Read in a series of integers into the vector.
    while(true) {

        std::cout << ">> ";
        double element{};
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

bool is_valid(const std::vector<double> &elements, int N) {
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

        std::cout << "\nPlease enter some floating-point values (press '|' to stop):\n";
        std::vector<double> elements;
        read_values(elements);

        if(!is_valid(elements, N)) {

            std::cout << "\nThe sum of the first " << N << " numbers ( ";
            for(int i{}; i < N; ++i) {
                std::cout << elements[i] << ' ';
            }
            std::cout << ") is " << sum_of_N(elements, N) << ".\n\n";
        }
        else {
            throw std::runtime_error{bad_input_error};
        }

        std::vector<double> diff;
        diff_of_N(diff, elements, N);
        std::cout << "The differences of the first " << N << " adjacent values are:\n";
        for(double d : diff) {
            std::cout << d << ' ';
        }
        std::cout << '\n';

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