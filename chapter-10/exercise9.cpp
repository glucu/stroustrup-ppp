#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 9
 *
 * Write a program that takes two files containing sorted whitespace-separated
 * words and merges them, preserving order.
 */

void read_file(const std::string &file, std::vector<std::string> &words) {

    std::ifstream ist{file};
    if(ist.fail()) error("can't open file, ", file);
    ist.exceptions(ist.exceptions() | std::ios_base::badbit);

    for(std::string s; ist >> s;) {
        words.push_back(s);
    }

    if(ist.eof())  ist.clear();
    if(ist.fail()) error("contents were not formatted correctly.");
}

void write_file(const std::vector<std::string> &words, const std::string &oname) {

    std::ofstream ost{oname};
    if(ost.fail()) error("can't open file, ", oname);

    for(size_t i{}; i < words.size(); ++i) {
        ost << words[i] << ' ';
    }
}

void a_sort(std::vector<std::string> &words) {

    std::sort(words.begin(), words.end());
}

int main() {

    try {

        std::vector<std::string> words;

        std::cout << "Enter first file name: ";
        std::string file1;
        std::cin >> file1;
        read_file(file1, words);

        std::cout << "Enter second file name: ";
        std::string file2;
        std::cin >> file2;
        read_file(file2, words);

        a_sort(words);

        std::cout << "Now, enter output file: ";
        std::string oname;
        std::cin >> oname;

        write_file(words, oname);

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