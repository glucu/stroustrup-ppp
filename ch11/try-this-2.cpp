#include "std_lib_facilities.h"

int main()
{
    try {
       

        cin.unsetf(ios::dec);
        cin.unsetf(ios::hex);
        cin.unsetf(ios::oct);

        cout << "Please enter four numbers separated by a space that can be a decimal, hexadecimal, or octal number.\n"
             << "Example: 0x2df (hexadecimal) - 1234 (decimal) - 01234 (octal):\n";
        int a{}, b{}, c{}, d{};
        while(cin >> a >> b >> c >> d) {
            cout << showbase
                 << a << ' ' << b << ' ' 
                 << c << ' ' << d << '\n';

            cout << "Enter again (or non-digit to exit):\n";
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
