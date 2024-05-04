#include "std_lib_facilities.h"


bool is_prime(int n) {

    if(n == 1) return false;

    for(int i = 2; i != n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(const vector<int> &primes) 
{
    cout << "List of all primes between [1-100]:\n{";
    for(size_t i = 0; i != primes.size(); ++i) {
        cout << primes[i];
        if(i < primes.size() - 1) cout << ',';
    }
    cout << "}\n";
}

int main()
{
    try {
               
        cout << "This program finds all the prime numbers between the closed interval [1-100]\n\n";
        vector<int> primes;
        for(int i = 1; i <= 100; ++i) {
            if(is_prime(i)) {
                primes.push_back(i);
            }
        }

        print_primes(primes);

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
