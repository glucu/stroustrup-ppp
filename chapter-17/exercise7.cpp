#include <iostream>
#include <exception>

/* Chapter 17: exercise 7
 *
 * Write a program that reads characters from cin into an array that you allocate
 * on the free store. Read individual characters until an exclamation mark (!)
 * is entered. Do not use a std::string. Do not worry about memory exhaustion.
 */

constexpr char kQuit{'!'};

int main()
{
    try {

        std::cout << "How many characters would you like to enter?\n";
        int n{};
        std::cin >> n;

        std::cout << "Enter the " << n << " characters (" << kQuit << " to quit).\n";
        char *ca{ new char[n+1] };
        char ch{' '};
        for(int i{}; std::cin >> ch && i != n && ch != kQuit; ++i) {
            ca[i] = ch;
        }

        ca[n+1] = '\0';

        for(int i{}; i != n; ++i) {
            std::cout << ca[i] << ' ';
        }
        std::cout << '\n';

        delete[] ca;

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
