#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 1
 *
 * Write a program that produces the sum of all the numbers in a file of
 * whitespace-separated integers.  
 */

/* COMMENT:
 * I went on https://www.random.org/integers/
 * and randomly generated 100 integers in the [1-500]
 * range for my ints.txt file. I also assume the file is really
 * a file with just integers as it says. So I decided not to recover.
 */

const std::string kFile_name{"ints.txt"};

int sum(std::ifstream &ist) {

    int total{};
    int x{};
    while(!ist.eof()) {
        ist >> x;
        total += x;
    }

    return total;
}

int open_file() {
    
    std::ifstream ist{kFile_name};
    if(ist.fail()) error("can't open file ", kFile_name);

    int total{ sum(ist) };
    return total;
}

int main() {

    try {

        int total{ open_file() };
        std::cout << "The sum is " << total << '\n';

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}