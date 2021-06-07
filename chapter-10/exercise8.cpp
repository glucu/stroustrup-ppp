#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 8
 *
 * Write a program that accepts two ftle names and produces a new file that
 * is the contents of the first ftle followed by the contents of the second; that
 * is, the program concatenates the two files.
 */

std::string read_file(std::string &file) {

    ifstream ist{file};
    if(ist.fail()) error("can't open file, ", file);
    ist.exceptions(ist.exceptions() | std::ios_base::badbit);

    std::string temp;
    while(!ist.eof()) {

        char ch = ist.get();
        if(!ist.eof()) temp += ch;
    }

    if(ist.eof())  ist.clear();
    if(ist.fail()) error("contents were not formatted correctly.");

    return temp;
}

void write_file(const std::string &file, std::string &oname) {

    std::ofstream ost{oname};
    if(ost.fail()) error("can't open file, ", oname);

    for(size_t i{}; i < file.size(); ++i) {
        ost << file[i];
    }
}

int main() {

    try {

        std::cout << "Please enter the first file to read: ";
        std::string file1;
        std::cin >> file1;
        std::string result1{ read_file(file1) };

        std::cout << "Please enter the second file to read: ";
        std::string file2;
        std::cin >> file2;
        std::string result2{ read_file(file2) };

        std::cout << "Now, enter a output name: ";
        std::string oname;
        std::cin >> oname;

        result1 += '\n' + result2;
        write_file(result1, oname);

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