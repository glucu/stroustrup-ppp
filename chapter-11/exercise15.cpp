#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 15
 *
 * Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using 
 * scientific format and precision 8 in four fields of 20 characters per line. 
 */

void skip_to_double(std::ifstream &ifs) {
// recover from a unexpected character and 
// skip any nondigit characters.

    if(ifs.fail()) {

        ifs.clear();
        for(char ch; ifs >> ch;) {
            if(std::isdigit(ch)) {
                ifs.unget();
                return;
            }
        }
    }
    error("Bad input");
}

void read_file(std::vector<double> &numbers, const std::string &iname) {
// read from the file iname and push each digit in vector numbers.

    std::ifstream ifs{iname.c_str()};
    if(ifs.rdstate() != 0) error("can't open file, ", iname);

    double num{};
    while(!ifs.eof()) {

        if(ifs >> num) {
            numbers.push_back(num);
        }
        else {
            skip_to_double(ifs);
        }
    }
}

void write_file(const std::vector<double> &numbers, const std::string &oname) {
// write each number in a given format to file oname.
// pre-condition: vector numbers must be at least size 1.

    std::ofstream ofs{oname.c_str()};
    if(ofs.rdstate() != 0) error("can't open file, ", oname);

    if(numbers.empty()) return;

    for(size_t i{}; i < numbers.size(); ++i) {
        ofs << std::scientific << std::setprecision(8)
            << std::setw(20) << numbers[i];

        if(i != 0 && i % 4 == 0) ofs << '\n';
    }
}

int main() {

    try {

        std::vector<double> numbers;
        std::cout << "Please enter the input file name: ";
        std::string iname;
        std::cin >> iname;

        read_file(numbers, iname);

        std::cout << "Please enter the output file name: ";
        std::string oname;
        std::cin >> oname;

        write_file(numbers, oname);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Excepption: something went wrong.\n";
        return 2;
    }
}