#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 5
 *
 * Write a program that reads strings and for each string outputs 
 * the char­acter classification of each character, as defined by the character 
 * classifi­cation functions presented in §11.6. Note that a character can have several 
 * classifications (e.g., x is both a letter and an alphanumeric). 
 */

std::string report_char(char ch) {
// return for each character all its classifications

    if(std::isspace(ch))
        return "isspace";
    if(std::isalpha(ch))
        return "isalpha";
    if(std::isdigit(ch))
        return "isdigit";
    if(std::isxdigit(ch)) 
        return "isxdigit";
    if(std::isupper(ch))
        return "isupper";
    if(std::islower(ch))
        return "islower";
    if(std::isalnum(ch))
        return "isalnum";
    if(std::iscntrl(ch))
        return "iscntrl";
    if(std::ispunct(ch))
        return "ispunct";
    if(std::isprint(ch))
        return "isprint";
    if(std::isgraph(ch))
        return "isgraph";
}

void print(const std::string &res, char ch) {

    std::cout << ch << " is " << res << '\n';
}

const std::string kStop{"stop"};

int main() {

    try {

        cout << "Please enter a series of strings\n(Enter " << kStop << " to finish): ";
        std::string s;
        std::string res;
        while(std::cin >> s && !(s == kStop)) {

            for(const auto &ch : s) {
                res = report_char(ch);
                print(res, ch);
            }
            std::cout << '\n';
        }

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