#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 2
 *
 * Write a program that given a file name and a word outputs
 * each line that contains that word together with the line number.
 * Hint: getline().
 */

const std::string kInput_file{"exercise2-input.txt"};

void remove_punct(std::vector<std::string> &lines) {
// Converts punctuation to whitespace

    for(std::string &s : lines) {
        for(char &ch : s) {

            if(std::ispunct(ch)) {
                ch = ' ';
            }
        }
    }
}
std::string tolower(std::string &word) {
// For every word, convert each character
// to lower case.

    for(auto &ch : word) {
        if(std::isalpha(ch)) {
            ch = std::tolower(ch);
        }
    }

    return word;
}

std::vector<std::string> read_lines(std::ifstream &ifs) {

    std::vector<std::string> temp;
    while(ifs) {

        std::string line;
        std::getline(ifs, line);
        temp.push_back(line);
    } 

    return temp;
}

bool search_word(const std::string &user_word, const std::string &line) {

    std::istringstream iss{line};
    for(std::string s; iss >> s;) {
        if(s == user_word) return true;
    }

    return false;
}

int main() {
    
    try {
        
        std::ifstream ifs{kInput_file};
        if(ifs.fail()) error("can't open file, ", kInput_file);

        std::vector<std::string> lines{ read_lines(ifs) };
        remove_punct(lines);

        std::cout << "Please enter a word to search for: ";
        std::string user_word;
        std::cin >> user_word;

        for(size_t i{}; i < lines.size(); ++i) {

            if(search_word(tolower(user_word), tolower(lines[i]))) {

                std::cout << "line " << (i+1) << ": " << lines[i] << '\n';
            }
        }

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