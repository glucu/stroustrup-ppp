#include "std_lib_facilities.h"

int main() 
{
    try {

        cout << "Please enter the number of miles and I will convert it to kilometers\n"
             << "Enter \'Ctrl-Z\' on Windows or \'Ctrl-D\' on Unix to quit the program:\n";
        int m = 0;
        while(cin >> m) {
            if(m < 0) cout << "negative number entered. Try again:\n";
            else {
                cout << m << " mi == " << m * 1.609 << " km.\n"
                     << "Try again? "; 
            }
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
