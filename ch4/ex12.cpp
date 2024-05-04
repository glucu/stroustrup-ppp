#include "std_lib_facilities.h"

// COMMENT:
// Because we are calculating all prime numbers between [1-n], where n is the max value entered,
// we need to keep in mind about overflow. An overflow would result in a very large negative number.
// So we can test to see if it is negative. 

bool is_prime(int n) 
{
    if(n == 1) return false;

    for(int i = 2; i != n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

void print_primes(const vector<int> &primes, int max) 
{
    cout << "List of all primes between [1-" << max << "]:\n{";
    for(size_t i = 0; i != primes.size(); ++i) {
        cout << primes[i];
        if(i < primes.size() - 1) cout << ',';
    }
    cout << "}\n";
}


int main()
{
    try {
      
        vector<int> primes;
        cout << "Please enter a max value of prime numbers:\n";
        int max{};
        while(cin >> max) {
            if(max <= 1) error("Not a valid read", max);
            if(max == 2) primes.push_back(max);
            for(int i = 1; i != max; ++i) {
                if(is_prime(i)) {
                    primes.push_back(i);
                }
            }

            print_primes(primes, max); 

            cout << "Try again ";
        } 
        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
