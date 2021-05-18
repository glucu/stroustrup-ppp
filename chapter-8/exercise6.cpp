#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 6
 *
 * Write versions of the functions from exercise 5, but with a vector<String>.
 */

std::vector<std::string> reverse_cr(const std::vector<std::string> &vs) {
// produces a new vector with the reversed sequence, leaving its
// original vector unchanged.
// pre-condition: vector must be at least size 2 to be able to reverse

    if(vs.size() == 0) return {};
    if(vs.size() == 1) return {vs[0]};

    std::vector<std::string> temp;
    int n = vs.size() - 1;
    for(int i{n}; i >= 0; --i) {
        temp.push_back(vs[i]);
    }

    return temp;
}

void reverse_r(std::vector<std::string> &vs) {
// reverses the sequence of the passed vector
// in-place (allocating no more than constant variables outside)
// pre-condition: vector must be at least 2 to be able to reverse

    if(vs.size() < 2) return;

    int n = vs.size();
    for(int i{}; i < (n / 2); ++i) {
        std::swap(vs[i], vs[n - 1 - i]);
    }
}

void print(const std::vector<std::string> &vs, const std::string &label) {

    std::cout << label << ": { ";
    for(size_t i{}; i < vs.size(); ++i) {
        if(i % 8 == 0) std::cout << '\n';

        std::cout << vs[i];
        if(i != vs.size()-1) std::cout << ", ";
    }
    std::cout << " }\n";
}

const std::string quit{'q'};

int main() {

    try {

        std::vector<std::string> vals;
        std::cout << "Please enter a series of strings (followed by 'q' to quit):\n";
        std::string val{};
        while(std::cin >> val &&  val != quit) {
            vals.push_back(val);
        }

        print(vals, "original");
        std::vector<std::string> result{ reverse_cr(vals) };
        print(result, "reverse_cr()");

        reverse_r(vals);
        print(vals, "reverse_r()");

        return 0;
    }
    catch(const std::exception &e) {
        std::cout << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong!\n";
        return 2;
    }
}