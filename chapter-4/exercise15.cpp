#include "../include/std_lib_facilities.h"

std::vector<bool> sieve_eratosthenes(int min, int max) {

    std::vector<bool> vb(max, true);
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

	std::cout << "Starting prime number: "; 
    int min{};
    std::cin >> min;

	std::cout << "Up to: "; 
    int max{};
    std::cin >> max;

	std::vector<bool> result{ sieve_eratosthenes(min, max) };

	for (int i{min}; i < result.size(); ++i) {
		if (result[i])
			cout << i << " ";
	}
    std::cout << '\n';
    
    return 0;
}