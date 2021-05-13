#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 4
 *
 * An int can hold integers only up to a maximum number. 
 * Find an approximation of that maximum number by using fibonacci(). 
 */

void print(const std::vector<int> &vi, const std::string &label) {
// prints out the integers of the vector vi
// pre-condition: size of vector must be at least one.

    if(vi.size() == 0) return;

    std::cout << label << ": {";
    for(size_t i{}; i < vi.size(); ++i) {
        std::cout << vi[i];
        if(i != vi.size()-1) std::cout << ", ";
    }
    std::cout << '}';
}

int fibonacci(int x, int y, std::vector<int> &v, int n) {
// generates the first n sequence of fibonacci numbers and stores
// it in the vector paramemter v. Returns the maximum number an int
// can hold.

    v.push_back(x);
    v.push_back(y);
    int approx{};
    int i;
    try {

        for(i = 2; i < n; ++i) {

            int sum{ v[i-2] + v[i-1] };
            if(sum < y) throw std::overflow_error{"fibonacci(): overflow detected."};

            v.push_back(sum);
        }
    }
    catch(const std::exception &e) {
        std::cerr << e.what() << "\n\n";
        approx = i;
    }

    return approx;
}


int main() {

    std::vector<int> fib;
    int max{ fibonacci(1, 2, fib, 50) };

    print(fib, "Fib()"); std::cout << '\n';
    std::cout << "Maximum integer approximation: " << max << "\n\n";

    return 0;
}