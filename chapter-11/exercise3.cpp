#include "../include/std_lib_facilities.h"


/* Chapter 11: exercise 3
 *
 * Write a program that removes all vowels from a file ("disemvowels"). For
 * example, Once upon a time! becomes nc pn tm!. Surprisingly often, the
 * result is still readable; try it on your friends.
 */

const std::string kFile_input{"dickens.txt"};
const std::string kFile_output{"exercise3-output.txt"};

std::vector<std::string> read_file(std::ifstream &ifs) {
// reads in from kFile_input and stores each line
// in vector and returns it.

    std::vector<std::string> temp;
    while(!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        temp.push_back(line);
    }

    if(ifs.eof()) ifs.clear();
    if(ifs.fail()) error("read_file(): Format error");

    return temp;
}

void write_file(const std::vector<std::string> &lines) {
// write out the change to kFile_output

    std::ofstream ofs{kFile_output};
    if(ofs.rdstate() != 0) error("can't write to file, ", kFile_output);

    for(size_t i{}; i < lines.size(); ++i) {

        if(i != 0 || i % 10 == 0) ofs << '\n';
        ofs << lines[i] << ' ';
    }
}

bool is_vowel(char ch) {
// return true if ch is a vowel; otherwise
// return false.

    switch(ch) {
    case 'a': case 'e': 
    case 'i': case 'o': case 'u':
        return true;
    default:
        return false;
    }
}

std::string remove_vowels(std::string &line) {
// remove all vowels in each word in line
// and return a new string.

    std::istringstream iss{line};
    std::string temp;
    for(std::string word; iss >> word;) {
        for(char &ch : word) {
            ch = std::tolower(ch);
            if(!is_vowel(ch)) {
                temp += ch;
            }
        }

        temp += ' ';
    }

    return temp;
}
int main() {

    try {

        std::ifstream ifs{kFile_input};
        if(ifs.rdstate() != 0) error("can't open file, ", kFile_input);

        std::vector<std::string> lines{ read_file(ifs) };

        for(size_t i{}; i < lines.size(); ++i) {
            lines[i] = remove_vowels(lines[i]);
        }

        write_file(lines);

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