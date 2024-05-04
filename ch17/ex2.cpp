#include "std_lib_facilities.h"

/*
 * COMMENT:
 * int: On most desktop PC and laptops, an int is 32-bits (a byte or word)
 * double: Usually 64-bits (8 bytes or two words)
 * bool: Usually 8-bits (1 byte)
 */

int main()
{
    try {

        cout << "sizof(int) is " << sizeof(int) << '\n'
             << "sizeof(double) is " << sizeof(double) << '\n'
             << "sizeof(bool) is " << sizeof(bool) << '\n';
         
        return 0;
    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
