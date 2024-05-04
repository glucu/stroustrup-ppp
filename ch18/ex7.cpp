#include <iostream>
#include <stdexcept>
#include <string>

/*
 * COMMENT:
 * The standard library string is less effort and trivial. However,
 * dealing with C-Style strings without using the standard library functions
 * is requires more effort and tedious. You need to make sure you allocate room for the 
 * null terminator, give the responsibility to the caller to free the resource allocated
 * on the heap, and being careful not to access an invalid pointer through misuse of
 * pointer arithmetic.
 *
 */

int size(const char *ca)
{
    int cnt{};
    while(ca[cnt]) ++cnt;
    return cnt;
}

char* cat_dot(const char *ca1, const char *ca2, const char *sep = ".")
{
    const int ca1_n = size(ca1);
    const int ca2_n = size(ca2);
    const int sep_n = size(sep);

    const int res_n = ca1_n + ca2_n + sep_n + 1;
    char* res = new char[res_n];

    while(*ca1) {
        *res = *ca1;
        ++res;
        ++ca1;
    }

    while(*sep) {
        *res = *sep;
        ++res;
        ++sep;
    }

    while(*ca2) {
        *res = *ca2;
        ++res;
        ++ca2;
    }

    *res = 0;
    res = res - res_n + 1; // Note: compound assignment (-=) does not work. it has lower precedence than +
    
    return res;
}

const std::string kQuit{"q!"};

int main()
{
    try {
        
        std::string s1;
        std::string s2;
        std::string sep;
        while(std::cin >> s1 && s1 != kQuit && std::cin >> s2 >> sep) {
            char *res = cat_dot(s1.c_str(), s2.c_str(), sep.c_str());
            std::cout << res << '\n';
            delete[] res;
        }

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
