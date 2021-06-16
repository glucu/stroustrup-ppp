#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 7
 *
 * Modify the program from the previous exercise so that it replaces don't with do not, 
 * can't with cannot, etc.; leaves hyphens within words intact (so that we get " do not use the as-if rule "); 
 * and converts all characters to lower case. 
 */

const std::string kFile_input{"bible.txt"};
const std::string kFile_output{"exercise7-output.txt"};
const std::string whitespace{".;,?-'"};

bool is_whitespace(char ch) {
// return true if ch is considered whitespace

    for(const char &c : whitespace) {
        if(c == ch) return true;
    }

    return false;
}

void to_lower(std::string &s) {
// convert any uppercase character
// to lowercase.

    for(char &ch : s) {
        if(std::isalpha(ch))
            ch = std::tolower(ch);
    }
}

void remove_hyphen(std::string &s) {
// removes '-' when not present within words

    if(s[0] == '-' && s[1] == ' ') s[0] = ' ';
    int len = s.size();
    if(s[len - 1] == '-' && s[len - 2] == ' ') s[len-1] = ' ';
    for(int i{1}; i < len - 1; ++i) {
        if(s[i] == '-' && s[i - 1] == ' ' && s[ i + 1] == ' ') s[i] = ' ';
        if(s[i] == '-' && s[i + 1] == '-') {
            s[i] = ' ';
            s[i + 1] = ' ';
            ++i;
        }
    }
}

void write_file(const std::string &word) {

    std::ofstream ofs{kFile_output, std::ios_base::app};
    if(ofs.rdstate() != 0) error("can't open file, ", kFile_output);

    ofs << word << ' ';
}

std::vector<std::string> read_lines(std::ifstream &ifs) {
// reads in a line of text from ifs into vector temp

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

void convert_contraction(std::string &s) {
// replace's "don't" with "do not" and "can't" with "cannot".
    std::string exp;
    std::string word;
    std::ostringstream oss{exp};
    std::istringstream iss{s};
    while(iss >> word) {
        if(s == "can't") 
            oss << "cannot";
        else if(s == "don't") 
            oss << "do not";
        else
            oss << word;
        oss << ' ';
    }
    s = oss.str();
}

void parse_line(std::string &line) {
// for each line, parse a word at a time

    std::stringstream ss{line};
    std::string s;
    while(ss >> s) {
        to_lower(s);
        convert_contraction(s);
        remove_hyphen(s);
        for(char &ch : s) {
            if(is_whitespace(ch)) {
                ch = ' ';
            }
        }

        write_file(s);
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
        
        std::cout << "Done writing to " << kFile_output << "\n\n";
        
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