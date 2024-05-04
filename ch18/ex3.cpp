#include <iostream> 
#include <stdexcept>

int size(const char *s)
{
    int cnt{};
    while(*s++) ++cnt;
    return cnt;
}

int strcmp(const char *s1, const char *s2)
{
    if(!s1 || !s2) throw std::invalid_argument{"strcmp: one or more arguments are null pointers"};

    const int s1_n = size(s1);
    const int s2_n = size(s2);
    if(s1_n == s2_n) {
        while(*s1) {
            if(*s1 != *s2) {
                if(*s1 < *s2) return -1;
                else          return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
    else {
        int n = (s1_n < s2_n) ? s1_n : s2_n;
        for(int i{}; i != n; ++i) {
            if(*s1 != *s2) {
                if(*s1 < *s2) return -1;
                else          return 1;
            }
            ++s1;
            ++s2;
        }
        if(s1_n < s2_n) return -1;
        return 1;
    }
}

const std::string kQuit{"q!"};

int main()
{
    try {
       

        for(std::string s1, s2; std::cin >> s1 && s1 != kQuit && std::cin >> s2;) {
            std::cout << strcmp(s1.c_str(), s2.c_str()) << '\n';
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
