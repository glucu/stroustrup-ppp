#include <iostream>
#include <string>
#include <stdexcept>

char* strdup(const char *s)
{
    if(!s) return nullptr;

    std::size_t n{};
    while(*(s+n)) ++n;

    char *s_cpy = new char[n+1];

    std::size_t i{};
    while(i != n) {
        *(s_cpy+i) = *(s+i);
        ++i;
    }

    *(s_cpy+i) = 0;

    return s_cpy;
}

const std::string kQuit{"q!"};

int main()
{
    try {

        for(std::string s; std::getline(std::cin, s) && s != kQuit;) {
            std::cout << "Input:\t" << s << '\n';
			char *s_cpy = strdup(s.c_str());
            std::cout << "Output:\t" << s_cpy << '\n';
			delete[] s_cpy;
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
