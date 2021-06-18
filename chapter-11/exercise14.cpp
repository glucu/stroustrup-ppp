#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 14
 *
 * Write a program that reads a text file and writes out how many characters of each character classification (§11.6)
 * are in the file.
 */

/* COMMENT:
 * Oh boy... global variables are no bueno! But for such a simple exercise, I think it's okay.
 * As long as you're aware of the cons of using global variables in larger programs.
 */

int space{}, alpha{}, digit{}, xdigit{}, upper{}, lower{},
    alnum{}, cntrl{}, punct{}, prt{}, graph{};

void count_char_classification(char ch) {

    if(std::isspace(ch)) ++space;
    if(std::isalpha(ch)) ++alpha;
    if(std::isdigit(ch)) ++digit;
    if(std::isxdigit(ch)) ++xdigit;
    if(std::isupper(ch)) ++upper;
    if(std::islower(ch)) ++lower;
    if(std::isalnum(ch)) ++alnum;
    if(std::iscntrl(ch)) ++cntrl;
    if(std::ispunct(ch)) ++punct;
    if(std::isprint(ch)) ++prt;
    if(std::isgraph(ch)) ++graph;
}

void print() {

    std::cout << "isspace:\t"  << space   << '\n';
    std::cout << "isalpha:\t"  << alpha   << '\n';
    std::cout << "isdigit:\t"  << digit   << '\n';
    std::cout << "isxdigit:\t" << xdigit  << '\n';
    std::cout << "isupper:\t"  << upper   << '\n';
    std::cout << "islower:\t"  << lower   << '\n';
    std::cout << "isalnum:\t"  << alnum   << '\n';
    std::cout << "iscntrl:\t"  << cntrl   << '\n';
    std::cout << "ispunct:\t"  << punct   << '\n';
    std::cout << "isprint:\t"  << prt     << '\n';
    std::cout << "isgraph:\t"  << graph   << '\n';
}

int main() {

    try {

        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        std::ifstream ifs{iname.c_str()};
        if(ifs.rdstate() != 0) error("can't open file, ", iname);

        char ch{' '};
        while(ifs.get(ch)) {
            count_char_classification(ch);
        }
        std::cout << '\n';

        print();

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