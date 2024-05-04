#include "std_lib_facilities.h"

// COMMENT:
// I done this exercise with only the test for int type and not double.
// The C++ standard committee guarantees a minimum size for an int to be 16 bits (2 bytes or half a word)
// However, on most Desktop computers, an int is 32 bits (4 bytes or a word) which means that an int can store
// values of no more than 2^31 (2147483648). Anything that is computed over that is considered an overflow.

int main()
{
    try {
       
        int total_square = 0;
        int rice_grain = 1;
        int total_rice_grains = 0;
        for(int square = 1; square <= 64; ++square) {
            if(total_rice_grains + rice_grain < 1) break;
            ++total_square;
            total_rice_grains += rice_grain;
            rice_grain *= 2;
        }
        cout << "The maximum number of squares that fits in an int is " << total_square << '\n';
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
