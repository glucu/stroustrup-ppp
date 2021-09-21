#include <iostream>
#include <string>
#include <exception>

/* Chapter 17: exercise 8
 *
 * Do exercise 7 again, but this time read into a std::string rather than to
 * memory you put on the free store (string knows how to use the free store for you).
 */

constexpr char kQuit{'!'};

void print(const std::string &result)
{ 
    for(const auto &ch : result) {
        std::cout << ch << ' ';
    }
    std::cout << '\n';
}

int main()
{
    try {

        std::string result;
        std::cout << "Enter characters and then enter " << kQuit << " to quit.\n";
        for(char ch; std::cin >> ch && ch != kQuit;) {
            result.push_back(ch);
        }

        std::cout << "You entered: ";
        print(result);

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
