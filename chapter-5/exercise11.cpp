#include "../include/std_lib_facilities.h"

/*  Chapter 5: exercise 11
 *
 *  Write a program that writes out the first so many values of the Fibonacci
 *  series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
 *  number of the series is the sum of the two previous ones. Fmd the largest
 *  Fibonacci number that fits in an int.
 */

/*  COMMENT:
 *  To recall, an int is 32 bits (4 bytes) that is 2^31-1 So, -2,147,483,648 to 2,147,483,647
 *  possible values. If sum adds the two previous fibs and that sum becomes negative, we know
 *  we reached an overflow. I added a std::cout before calling error() to see which number is 
 *  the maximum number that doesn't fit in an int.
 */


std::vector<int> fibs;

void solve_fib(int n) {

    int fib{1};
    int fib1{1};
    fibs.push_back(fib);
    fibs.push_back(fib1);
    
    for(int i{2}; i < n; ++i) {
        int sum{fib + fib1};
        if(sum < fib1) {
            std::cout << i+1 << ' ';
            error("caused an overflow");
        }

        fib = fib1;
        fib1 = sum;
        fibs.push_back(fib1);
    }
} 

int main() {

    try {

        std::cout << "How many Fibonacci numbers do you want to print?:\n";
        std::cout << ">> ";
        int n{};
        std::cin >> n;
        if(!std::cin) error("Could not read in a integer");
        if(n < 1)     error("Can't be a negative number");
        
        solve_fib(n);
        for(size_t i{}; i < fibs.size(); ++i) {
            std::cout << fibs[i] << ' ';
        }
        
        return 0;
    }
    catch(const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}