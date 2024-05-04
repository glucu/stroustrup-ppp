#include "std_lib_facilities.h"

int main()
{
    try {
       
        cout << "This program writes out the first so many values of the Fibonacci series.\n\n";
        int fib1 = 0;
        int fib2 = 1;
        cout << fib1 << ' ' << fib2 << ' ';
        while(fib1 + fib2 > 0) {
            int fib3 = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib3;
            cout << fib3 << ' ';
        }

        cout << "\n\nThe largest fibonacci number that fits in an int is " << fib2 << '\n';

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
