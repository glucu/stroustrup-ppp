#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 4
 *
 * Write a program called multi_input.cpp that prompts the user to enter
 * several integers in any combination of octal, decimal, or hexadecimal,
 * using the 0 and Ox base suffixes; interprets the numbers correctly; and
 * converts them to decimal form. Then your program should output the
 * values in properly spaced columns like this:
 * 
 * Ox4  hexadecimal converts to 67 decimal
 * 0123 octal       converts to 83 decomal
 * 65   decimal     converts to 65 decimal
 */

bool is_number(const std::string &s) {

    for(const char &ch : s) {
        if(!std::isxdigit(ch) && ch != 'x') {
            return false;
        }
    }

    return true;
}

std::stringstream convert_to_decimal(std::string &s) {

    using std::setw;

    int num{ std::stoi(s.c_str(), nullptr, 0) };
    std::stringstream ss;
    
    if(s.size() == 1) {
        ss << setw(4) << s << setw(12) << "decimal" << " converts to " << num << " decimal\n";
    }
    else if(s[0] == '0' && s[1] == 'x') {
        ss << setw(4) << s << setw(12) << "hexadecimal" << " converts to " << std::dec << num << " decimal\n";
    } 
    else if(s[0] == '0') {
        ss << setw(4) << s << setw(12) << "octal" << " converts to " << std::dec << num << " decimal\n";
    }
    else {
        ss << setw(4) << s << setw(12) << "decimal" << " converts to " <<  num << " decimal\n";
    }

    return ss;
}

void print(const std::vector<std::string> &vs) {

    for(size_t i{}; i < vs.size(); ++i) {
        
         std::cout << vs[i] << '\n';
    }
}

const std::string quit{"quit"};

int main() {

    try {

        std::vector<std::string> res;
        std::string s;
        cout << "Please enter octal, decimal, and hexadecimal numbers\n(Enter " << quit << " to stop): ";
        while(std::cin >> s && !(s == quit)) {

            if(is_number(s)) {
                res.push_back(convert_to_decimal(s).str());
            }
            else {
                std::cout << "Ops, that wasn't a number. Try again:\n";
            }
        }

        print(res);

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