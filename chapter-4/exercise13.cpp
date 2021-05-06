#include "../include/std_lib_facilities.h"

std::vector<bool> sieve_eratosthenes() {

    std::vector<bool> vb(100, true);
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

    std::vector<bool> result{ sieve_eratosthenes() };

    for(int i{2}; i < result.size(); ++i) {
        if(result[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}