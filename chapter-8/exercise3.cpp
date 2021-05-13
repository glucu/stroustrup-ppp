#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 3
 *
 * Create a vector of Fibonacci numbers and print them using the function
 * from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n),
 * where integers x and y are ints, v is an empty vector<int>, and n is the
 * number of elements to put into v; v[0] will be x and v[1] will be y. A
 * Fibonacci number is one that is part of a sequence where each element is
 * the sum of the two previous ones. For example, starting with 1 and 2, we
 * get 1, 2, 3, 6, 9, 15, 24, . . . . Your fibonacci() function should make such
 * a series starting with its x and y arguments. 
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

void fibonacci(int x, int y, std::vector<int> &v, int n) {
// generates the first n sequence of fibonacci numbers and stores
// it in the vector paramemter v.

    v.push_back(x);
    v.push_back(y);
    for(int i{2}; i < n; ++i) {

        int sum{ v[i-2] + v[i-1] };
        if(sum < y) throw std::overflow_error{"fibonacci(x,y,v,n): overflow detected."};

        v.push_back(sum);
    }
}

int main() {

    try {
        
        const std::string label{"Fib(15)"};
        std::vector<int> fib;
        fibonacci(1, 2, fib, 15);
        print(fib, label);

        return 0;
    }
    catch(const std::overflow_error &e) {
        std::cerr << "overflow error: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}