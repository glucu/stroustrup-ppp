#include "../include/std_lib_facilities.h"

std::vector<int> primes;

bool is_prime(int n) {

     for (int i{}; primes[i] <= std::sqrt(n); ++i) {
        if (n % primes[i] == 0)
            return false;
    }

    return true;
}

int main() {

    primes.push_back(2);

    for(int i{3}; i < 100; i += 2) {
        if(is_prime(i)) {
            primes.push_back(i);
        }
    }

    for(const int p : primes) {
        std::cout << p << ' ';
    }
    std::cout << '\n';

    return 0;
}