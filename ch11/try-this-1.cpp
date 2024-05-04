#include "std_lib_facilities.h"

int main()
{
    try {
       
        cout << "Please enter your birth year and age (separated by a space):\n";
        for(int year{}, age{}; cin >> year >> age;) {
            cout << year << "\t(decimal)\n"
                 << hex << year << "\t(hexadecimal)\n"
                 << oct << year << "\t(octal)\n\n"
                 << dec << age << "\t(decimal)\n"
                 << hex << age << "\t(hexadecimal)\n"
                 << oct << age << "\t(octal)\n\n"
                 << "Try again please:\n";
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
