#include "../include/std_lib_facilities.h"

/*  Chapter 8: exercise 10
 *
 *  Write a function maxv() that returns the largest element of a vector
 *  argument.
 */ 

double maxv(const std::vector<double> &numbers) {
// find and return the maximum element
// found in the vector numbers.
// pre-condition: size of vector numbers must be at least one.

    if(numbers.size() == 0) error("maxv(): pre-condition violated");

    double max{numbers[0]};
    for(size_t i{1}; i < numbers.size(); ++i) {
        if(max < numbers[i]) max = numbers[i];
    }

    return max;
}

constexpr int min_val{1};
constexpr int max_val{100};

std::vector<double> init() {

    std::vector<double> temp;
    for(int i{}; i < 15; ++i) {
        temp.push_back(randint(min_val, max_val));
    }

    return temp;
}

void print(const std::vector<double> &numbers, const std::string &label) {
// print the elements of vector numbers as read-only.

    std::cout << label << ": { ";
    for(size_t i{}; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if(i != numbers.size() - 1) std::cout << ", ";
    }
    std::cout << "} \n";
}

int main() {

    try {

        std::cout << "Generating random numbers...\n";
        std::vector<double> numbers{ init() };

        print(numbers, "Elements");

        double max{ maxv(numbers) };

        std::cout << "Maxmum number is: " << max << '\n';

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