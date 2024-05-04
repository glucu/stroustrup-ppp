#include "std_lib_facilities.h"


int get_user_input()
{
    while(true) {
        int n{};
        cin >> n;
        if(!cin) {
            if(cin.eof()) error("EOF reached");
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not read an integer. Try again.\n";
        }
        else {
            if(n < 1) cout << n << " is not at least 1 or more. Try again.\n";
            else      return n;
        }
    }
}

int is_prime(int n) 
{
    for(int i = 2; i != n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> n_primes(int n)
{
    vector<int> primes;
    for(int i = 0, k = 2; i < n; ++k) {
        if(is_prime(k)) {
            primes.push_back(k);
            ++i;
        }
    }
    return primes;
}


void print_primes(const vector<int> &primes, int n) 
{
   cout << "Here are the prime numbers between [1-" << n << "]\n{"; 
   for(int i = 0; i != int(primes.size()); ++i) {
       cout << primes[i];
       if(i != primes.size() - 1) cout << ',';
   }
   cout << "}\n";
} 

int main()
{
    try {
       
        cout << "How many prime numbers would you like to list? ";
        int n = get_user_input();
        vector<int> primes = n_primes(n); 
        print_primes(primes, n);        
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
