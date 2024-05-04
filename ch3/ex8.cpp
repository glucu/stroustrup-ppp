#include "std_lib_facilities.h"

int main()
{
    try {
        
        cout << "Please enter an integer and I will tell you if it is an even number of odd number:\n";
        int val = 0;
        while(cin >> val) {
            if(!cin) error("something went wrong with the read");

            if(val % 2) cout << "The value " << val << " is an odd number.\n";
            else        cout << "The value " << val << " is an even number.\n";

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
