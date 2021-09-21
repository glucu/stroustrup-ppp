#include <iostream>
#include <string>
#include <exception>

/* Chapter 17: exercise 4
 *
 * Write a function, char* strdup(const char*), that copies a C-style string 
 * into memory it allocates on the free store. Do not use any standard library 
 * functions.
 */

char* strdup(const char *s)
{ // makes a copy of s and returns that copy
  // pre-condition: s must not be null.

    if(!s) return nullptr;

    int len{};
    int k{};
    while(s[k++]) {
        ++len;
    }

    char *tmp{ new char[len+1] };
    k = 0;
    while(s[k] != '\0') {
        tmp[k] = s[k];
        ++k;
    }

    tmp[len] = '\0';

    return tmp;
}

const std::string kQuit{"quit"};

int main() 
{
    try {

        std::string str;
        char *pc;
        while(std::getline(std::cin, str) && str != kQuit) {
            pc = strdup(&str[0]); 
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