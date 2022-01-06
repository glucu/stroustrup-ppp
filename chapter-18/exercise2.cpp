#include <iostream>
#include <string>
#include <exception>

/* Chapter 18: exercise 2
 *
 * Write a function, char• findx(const char• s, const char• x), that finds the
 * first occurrence of the C-style string x in s. Do not use any standard library
 * functions. Do not use subscripting; use the dereference operator • instead.
 */

const char* findx(const char *s, const char *x) {
// finds the first occurrence of x in s.
// pre-condition: s and x must point to a
// valid state.

    if(!s || !x) return nullptr;

    const auto *x_orig = x;
    const char *start{};
    while(*s) {
        if(!*x) {
            return s;
        }
        if(*x == *s) {
            if(!start) start = s;
            ++x;
        } else {
            x = x_orig;
            start = nullptr;
        }
        ++s;
    }

    return start;
}

int main() {

    try {

        std::string s{"What a Lovely day to be learning C++!"};
        std::string x{"day"};
        auto *occur = findx(s.c_str(), x.c_str());
        if(occur)
            std::cout << occur << '\n';
        else
            std::cout << "find return NULL.\n";
        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Something went wrong.\n";
    }
}