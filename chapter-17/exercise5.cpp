#include <iostream>
#include <exception>

/* Chapter 17: exercise 5
 *
 * Write a function, char* findx(const char* s, const char* x), that finds the
 * first occurrence of the C-style string x in s.
 */

const char* findx(const char *s, const char *x)
{ //finds the first occurrence of x in s
  // pre-condition: s and x are not null

    if(!s || !x) return nullptr;

    for(int i{}; s[i]; ++i) {
        if(s[i] == x[0]) {
            int j{};
            while(x[j]) {
                if(s[i] != x[j]) {
                    break;
                }
                ++i;
                ++j;
            }

            if(x[j] == '\0') return &s[i-j];
        }
    }

    return nullptr;
}

int main()
{
    try {

        char *s = "Why is C++ the greatest language of all time?";
        char *x = "of all time";

        const char *sub = findx(s,x);

        if (!sub) {
            std::cout << "Not found!\n";
        }
        else  {
            std::cout << sub << '\n';
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
