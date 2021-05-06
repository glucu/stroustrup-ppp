#include "../include/std_lib_facilities.h"

std::vector<bool> sieve_eratosthenes(int N) {

    std::vector<bool> vb(N, true);
    int n = vb.size();

    for(int i{2}; i < std::sqrt(n); ++i) {
        if(vb[i]) {

            int tmp{1};
            for(int j{i*i}; j < n; j = (i*i) + (i*tmp)) {
                vb[j] = false;
                ++tmp;
            }
        }
    }

    return vb;
}

int main() {

    std::cout << "How many prime numbers should I find for you?\n";
    int n_primes{};
    std::cin >> n_primes;
    if(!std::cin)    error("Couldn't read a number");
    if(n_primes < 2) error("Can't work with that!");


    std::vector<bool> result{ sieve_eratosthenes(n_primes) };

    for(int i{2}; i < result.size(); ++i) {
        if(result[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}