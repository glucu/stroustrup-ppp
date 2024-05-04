#include "std_lib_facilities.h"

/*
 * Output:
 *
 * pi == 0x5556f92b0eb0
 * pd == 0x5556f92b0ed0
 *
 * The output format is in hexadecimal notation (base-16 system)
 * On a 64 bit architecture, all of the memory addresses are 64 bits (each hex digit is four bits, so that’s 16 hex digits). The leading zeros are dropped.
 * On a typical 32-bit architecture, there would only be 32 bits in a pointer, so only 8 hex digits. As a result, such an architecture can only use up to 4 GiB of RAM.
 *
 */

int main()
{
    try {

        cout << "Output Pointer Format:\n";
        int *pi = new int{77};
        double *pd = new double{3.14};
        cout << "pi == " << pi << '\n';
        cout << "&*pi == " << &*pi << '\n';
        cout << "pd == " << pd << '\n';
        cout << "&*pd == " << &*pd << '\n';

        delete pi;
        delete pd;

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
