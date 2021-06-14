#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 1
 *
 * Write a program that reads a text file and converts its input to all lower
 * case, producing a new file.
 */

const std::string kInput_name{"exercise1-input.txt"};
const std::string kOutput_name{"exercise1-output.txt"};

std::string tolower(std::string &word) {
// For every word in words, convert each character
// to lower case.

    for(auto &ch : word) {
        if(std::isalpha(ch)) {
            ch = std::tolower(ch);
        }
    }

    return word;
}

std::vector<std::string> read_file() {
// opens kInput_name for reading into a vector
// of words.

    std::ifstream is{kInput_name};
    if(is.fail()) error("can't open file, ", kInput_name);
    is.exceptions(is.exceptions() | std::ios_base::badbit);

    std::vector<std::string> temp;
    for(std::string word; is >> word;) {

        temp.push_back(tolower(word));
    }

    if(is.eof()) is.clear();
    if(is.fail()) error("read_file(): contents aren't formatted correctly.");

    return temp;
}

void write_file(const std::vector<std::string> &words) {
// writes the vector words to file.

    std::ofstream of{kOutput_name};
    if(of.fail()) error("can't open file, ", kOutput_name);
    
    for(size_t i{}; i < words.size(); ++i) {

        if(i != 0 && i % 10 == 0) of << '\n';

        of << words[i] << ' ';
    }
}

int main() {

    try {

        std::cout << "Reading file " << kInput_name << " now...\n";
        std::vector<std::string> words{ read_file() }; 
        std::cout << "Writing file " << kOutput_name << " now...\n";
        write_file(words);
        std::cout << "Done!\n";

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong.\n";
        return 2;
    }
}