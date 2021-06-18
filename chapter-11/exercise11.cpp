#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 11
 *
 * Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace-separated
 * substrings from the argument s, where whitespace is defined as "ordinary whitespace" plus the characters in w.
 */

std::vector<std::string> split(const std::string &s, const std::string &w) {
// returns whitespace-separated substrings of s, plus the characters in w.
// pre-condition: string s cannot be empty; otherwise
//                return empty vector

    if(s.empty()) return {};

    std::vector<std::string> temp;
    std::istringstream iss{s};
    std::string word;
    while(iss >> word) {
        if(word != w) {
            temp.push_back(word);
        }
    }

    if(iss.eof()) iss.clear();
    if(iss.fail()) error("split(): formatting process gone wrong.");

    return temp;
}

void print_substrings(const std::vector<std::string> &substrings) {
// prints whitespace-separated strings.
// pre-condition: string s cannot be empty; otherwise
//                return without printing.

    for(const std::string &s : substrings) {
        std::cout << s << ' ';
    }
}

const std::string kStop{"stop"};

int main() {

    try {

        std::cout << "Please enter a series of whitespace-separated strings\n (Followed by " << kStop << " to stop):\n";
        std::string s;
        std::string words;
        while(std::getline(std::cin, s) && s != kStop) {
            std::cout << "Now, enter some words:\n";
            std::getline(std::cin, words);
            std::vector<std::string> substrings{ split(s, words) };
            print_substrings(substrings); std::cout << '\n';
        }
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
