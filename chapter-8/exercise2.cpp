#include "../include/std_lib_facilities.h" 

/* Chapter 8: exercise 2
 *
 * Write a function print() that prints a vector of ints to cout. 
 * Give it two arguments: a string for "labeling" the output and a vector.
 */

void print(const std::vector<int> &vi, const std::string &label) {
// prints out the integers of the vector vi

    std::cout << label << ": { ";
    for(size_t i{}; i < vi.size(); ++i) {
        std::cout << vi[i];
        if(i != vi.size()-1) std::cout << ", ";
    }
    std::cout << " }\n";
}

std::vector<int> init(int n, int min, int max) {
// randomly generates n numbers between min-max inclusive.

    std::vector<int> result;
    for(int i{}; i < n; ++i) {
        result.push_back(randint(min, max));
    }

    return result;
}

void ignore_line() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clean_state() {

    std::cout << "Couldn't read a integer value. Try again.\n";
    std::cin.clear();
    ignore_line();
}

int main() {
    
    char do_again{' '};
    const std::string label{"sample data"};
    do {
        
        std::cout << "How many numbers do you want to generate?\n";
        int n{};
        std::cin >> n;
        if(std::cin.fail()) clean_state();
        else if(n < 1) std::cout << "n must be at least one.\n";
        else {
            
            std::cout << "Enter the min and max range of numbers to be randomly generated:\n";
            int min{}, max{};
            std::cin >> min >> max;
            if(std::cin.fail()) clean_state();
            else {

                std::vector<int> vi{ init(n, min, max) };
                print(vi, label);
            }
        }
        std::cout << "\n\n";

        std::cout << "Would you like to go again? (y/n):\n";
        std::cin >> do_again; std::cout << '\n';

    } while(std::tolower(do_again) != 'n');

    std::cout << "Goodbye!\n";

    return 0;
}