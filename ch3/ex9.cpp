#include "std_lib_facilities.h"

int main()
{
    try {
        
        cout << "Please enter a spelled-out digit (\'zero\', \'one\', \'two\', \'three\', or \'four\'):\n";
        string input;
        while(cin >> input && input != "Quit") {
            int digit = -1;
            if(input == "zero") {
                digit = 0;
            }
            else if(input == "one") {
                digit = 1;
            }
            else if(input == "two") {
                digit = 2;
            }
            else if(input == "three") {
                digit = 3;
            }
            else if(input == "four") {
                digit = 4;
            }
            else {
                cout << "Oops, I don't know a " << input << ". Try again.\n";
            }

            if(digit != -1) {
                cout << input << " == " << digit << '\n';
            }

            cout << "Please enter another spelled-out digit (or \'Quit\' to exit the program):\n";
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
