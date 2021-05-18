#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 5
 *
 * Write two functions that reverse the order of elements in a vector<int>. 
 * For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function
 * should produce a new vector with the reversed sequence, leaving its original vector unchanged. 
 * The other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).
 */


std::vector<int> reverse_cr(const std::vector<int> &vi) {
// produces a new vector with the reversed sequence, leaving its
// original vector unchanged.
// pre-condition: vector must be at least size 2 to be able to reverse

    if(vi.size() == 0) return {};
    if(vi.size() == 1) return {vi[0]};

    std::vector<int> temp;
    int n = vi.size() - 1;
    for(int i{n}; i >= 0; --i) {
        temp.push_back(vi[i]);
    }

    return temp;
}

void reverse_r(std::vector<int> &vi) {
// reverses the sequence of the passed vector
// in-place (allocating no more than constant variables outside)
// pre-condition: vector must be at least 2 to be able to reverse

    if(vi.size() < 2) return;

    int n = vi.size();
    for(int i{}; i < (n / 2); ++i) {
        std::swap(vi[i], vi[n - 1 - i]);
    }
}

void print(const std::vector<int> &vi, const std::string &label) {

    std::cout << label << ": { ";
    for(size_t i{}; i < vi.size(); ++i) {
        if(i % 8 == 0) std::cout << '\n';

        std::cout << vi[i];
        if(i != vi.size()-1) std::cout << ", ";
    }
    std::cout << " }\n";
}

int main() {

    try {

        std::vector<int> vals;
        std::cout << "Please enter a series of integers:\n";
        int val{};
        while(std::cin >> val) {
            vals.push_back(val);
        }

        print(vals, "original");
        std::vector<int> result{ reverse_cr(vals) };
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