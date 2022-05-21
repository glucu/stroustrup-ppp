#include <iostream>
#include <string>
#include <exception>

/* Chapter 17: exercise 4
 *
 * Write a function, char* strdup(const char*), that copies a C-style string 
 * into memory it allocates on the free store. Do not use any standard library 
 * functions.
 */

int getSize(const char *s) {
// returns the size of s

    int n{};
    while(s[n]) {
        ++n;
    }

    return n;
}

char* strdup(const char *s) { 
// makes a copy of s and returns that copy
// pre-condition: s must not be null.
    
    if(!s) {
        return nullptr;
    }

    auto n{ getSize(s) };

    auto *tmp{ new char[n+1] };
    n = {};
    while(s[n]) {
        tmp[n] = s[n];
        ++n;
    }
    
    tmp[n] = '\0';

    return tmp;
}

const std::string kQuit{"quit"};

int main() {

    try {

        std::string line;
        char *pc{};
        while(std::getline(std::cin, line) && line != kQuit) {
            pc = strdup(line.c_str()); 
            if(pc) {
                std::cout << pc << '\n';
            }
            else {
                std::cout << "empty string\n";
            }

            delete[] pc;
        }

		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "someting went wrong.\n";
		return 2;
	}
}