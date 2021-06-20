#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 16
 *
 * Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first),
 * one value per line. Write a value only once, and if it occurs more than once write the count of its occurrences
 * on its line. For example, "7 5 5 7 3 117 5" should give
 *
 * 3
 * 5    3
 * 7    2
 * 117
 */

void read_file(std::ifstream &ifs, std::vector<int> &numbers) {
// reads in from kFile_input into vector of numbers.

    int num{};
    while(!ifs.eof()) {
        ifs >> num;
        numbers.push_back(num);
    }

    if(ifs.eof()) ifs.clear();
    if(ifs.fail()) error("read_file(): failed to read integer.");
}

void sort(std::vector<int> &numbers) {
// sorts the numbers in nondecreasing order.

    std::sort(numbers.begin(), numbers.end());
}

void count_occurrences(const std::vector<int> &numbers, std::vector<int> &occurrs) {
// counts the number of occurrences for each number that appears in numbers.

    int count{1};
    for(size_t i{}; i < numbers.size(); ++i) {
        for(size_t j{i+1}; j < numbers.size(); ++j) {
            if(numbers[j] == numbers[i]) {
                ++count;
            }
        }

        if(count > 1) occurrs.push_back(count);
        else          occurrs.push_back(0);
        count = 1;
    }
}

const std::string kFile_input{"numbers.txt"};

int main() {

    try {

        std::ifstream ifs{kFile_input.c_str()};
        if(ifs.rdstate() != 0) error("can't open input file ", kFile_input);
         
        std::vector<int> numbers;
        read_file(ifs, numbers);
        sort(numbers);

        std::vector<int> occurrs;
        count_occurrences(numbers, occurrs);

        for(size_t i{}; i < numbers.size(); ++i) {

            if(i == 0 || numbers[i-1] != numbers[i])
                std::cout << numbers[i] << '\t' << occurrs[i] << '\n';
        }

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