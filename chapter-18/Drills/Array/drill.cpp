#include <iostream>
#include <cstddef>
#include <exception>

/* Chapter 18: Array drill
 *
 */

// #1
constexpr int gaSize{10};
int ga[gaSize]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

// #2
void f(int arr1[], int n) {

    // #3
    constexpr int laSize{10};
    int la[laSize]{};

    for(std::size_t i{}; i != gaSize; ++i) {
        la[i] = ga[i];
    }

    for(std::size_t i{}; i != laSize; ++i) {
        std::cout << la[i] << ' ';
    }
    std::cout << '\n';

    int *p{ new int[n] };

    for(std::size_t i{}; i != n; ++i) {
        p[i] = arr1[i];
    }

    for(std::size_t i{}; i != n; ++i) {
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';

    delete[] p;
    p = nullptr;
}

int main() {

    try {

        // #4
        f(ga, 10);

        constexpr int aaSize{10};
        int aa[aaSize]{1};
        for(std::size_t i{1}; i < aaSize; ++i) {
            aa[i] = aa[i-1] * (i+2);
        }
        f(aa, aaSize);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Something went wrong.\n";
        return 2;
    }
}