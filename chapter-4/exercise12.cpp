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

    std::cout << "How many prime numbers should I find for you?\n";
    int n_primes{};
    std::cin >> n_primes;
    if(n_primes < 2)
        error("Can't work with that!");

    primes.push_back(2);

    for(int i{3}; i < n_primes; i += 2) {
        if(is_prime(i)) {
            primes.push_back(i);
        }
    }

    for(const int p : primes) {
        std::cout << p << ' ';
    }
    std::cout << '\n';
}