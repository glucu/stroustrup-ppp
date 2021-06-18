#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 6
 *
 * Write a program that replaces punctuation with whitespace.
 * For exam­ple, " - don't use the as-if rule." becomes " dont use the as if rule".
 */

/* COMMENT:
 * I want to try something fun, so I will read from a text file that
 * contains the whole Bible. On VS Code, it shows over 30,000 lines!
 */

const std::string kFile_input{"bible.txt"};
const std::string kFile_output{"exercise6-output.txt"};
const std::string whitespace{".;,?-'"};

bool is_whitespace(char ch) {
// returns true if ch is whitespace;
// otherwise return false.

    for(const char &c : whitespace) {
        if(c == ch) return true;
    }

    return false;
}

void write_file(const std::string &word) {
// write each modified string by appending it to
// kFile-output.

    std::ofstream ofs{kFile_output, std::ios_base::app};
    if(ofs.rdstate() != 0) error("can't open file, ", kFile_output);

    ofs << word << ' ';
}

std::vector<std::string> read_lines(std::ifstream &ifs) {
// reads in each line from kFile_input and stores it in a
// vector.

    std::vector<std::string> temp;
    std::string line;
    while(!ifs.eof()) {

        std::getline(ifs, line);
        temp.push_back(line);
    }

    if(ifs.eof()) ifs.clear();
    if(ifs.fail()) error("read_line(): Failed to read from file.");

    return temp;
}

void parse_line(std::string &line) {
// for each line, parse a word at a time
// and check each character. If the character
// is a punctuation, convert it to space; otherwise
// skip it.

    std::stringstream ss{line};
    std::string word;
    while(ss >> word) {
        for(char &ch : word) {
            if(is_whitespace(ch)) {
                ch = ' ';
            }
        }

        write_file(word);
    }
}

int main() {

    try {

        std::ifstream ifs{kFile_input};
        if(ifs.rdstate() != 0) error("can't open file, ", kFile_input);

        std::vector<std::string> vs{ read_lines(ifs) };
        for(size_t i{}; i < vs.size(); ++i) {

            parse_line(vs[i]);
        }

        std::cout << "Done writing to file...\n";
        
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