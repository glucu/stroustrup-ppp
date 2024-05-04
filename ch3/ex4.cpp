#include "std_lib_facilities.h"

int main()
{
    try {
        cout << "Please enter two integers seperated by a space: ";
        int val1 = 0;
        int val2 = 0;
        cin >> val1 >> val2;
        if(!cin) error("something went wrong with the read");
        cout << "values entered: " << val1 << ' ' << val2 << '\n';

        if(val1 > val2) {
            cout << val2 << " is smallest.\n"
                 << val1 << " is largest.\n";
        }
        else if(val2 > val1) {
            cout << val1 << " is smallest.\n"
                 << val2 << " is largest.\n";
        }
        else {
            cout << val1 << " and " << val2 << " are equal.\n";
        }

        cout << "The sum of " << val1 << " and " << val2 << " is " << val1 + val2 << '\n';
        cout << "The difference of " << val1 << " and " << val2 << " is " << val1 - val2 << '\n';
        cout << "The product of " << val1 << " and " << val2 << " is " << val1 * val2 << '\n';
        if(val2 == 0) cout << "Sorry, divide by zero.\n";
        else          cout << "The ratio of " << val1 << " and " << val2 << " is " << val1 / val2 << '\n';

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
