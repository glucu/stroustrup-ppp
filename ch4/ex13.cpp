#include "std_lib_facilities.h"

vector<int> sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i{}; i <= sqrt(n); ++i) {
        if (is_prime[i]) {
            for (int j{i*i}; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i{2}; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

void print_primes(const vector<int> &primes) 
{
    cout << "Prime numbers between 1-100:\n{";
    for(size_t i{}; i != primes.size(); ++i) {
        cout << primes[i];
        if(i < primes.size() - 1) {
            cout << ',';
        }
    }
    cout << "}\n";
}


int main()
{
    try {
       
        cout << "This program finds all the prime numbers between [1-100] using the sieve of eratosthenes algorith\n";
        vector<int> primes = sieve_of_eratosthenes(100);
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
