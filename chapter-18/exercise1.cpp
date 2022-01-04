#include <iostream>
#include <exception>
#include <string>

char* strdupp(const char *source) {
// copies a C-style string into memory it
// allocates on the free store and returns it.
// pre-condition:  checks if source is NULL
    if(!source) return nullptr;

    std::size_t n{0};
    while(*source++) {
        ++n;
    }

    auto *tmp = new char[n+1];
    source-=n+1;

    while(*source) {
        *tmp = *source;
        ++tmp;
        ++source;
    }

    *(tmp) = '\0';
    tmp-=n;
    return tmp;
}

const std::string kQuit{"-1"};

int main() {

    try {

        std::string s;
        while(std::getline(std::cin, s) && s != kQuit) {
            auto *ans = strdup(s.c_str());
            std::cout << "Original: " << s << '\n';
            std::cout << "Copy: " << ans << '\n';
            delete[] ans;
        }

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Something went wrong.\n";
        return 2;
    }
}