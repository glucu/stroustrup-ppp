#include <iostream>
#include <exception>

/* Chapter 17: exercise 6
 *
 * This chapter does not say what happens when you run out of memory.
 * using new. That's called memory exhaustion. Find out what happens. You
 * have two obvious alternatives: look for documentation, or write a pro­
 * gram with an infinite loop that allocates but never deallocates. Try both.
 * Approximately how much memory did you manage to allocate before
 * failing?
 */

int main()
{
    try {

        unsigned long long total_bytes{};
        while (true) {
            std::cout << ++total_bytes << " MB\n";
            double *pd{ new double[131072] };
        }

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cout << "something went wrong.\n";
    }
}
