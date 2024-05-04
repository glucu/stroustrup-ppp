#include "std_lib_facilities.h"

/*
 * COMMENT:
 * It depends on the context. When it comes to very large (or very small) numbers, scientific notation
 * can enhance comprehension by making the number more compacted by splitting
 * it into two notations which is the mantissa field and the exponent field. fixed
 * is useful when you want a specific number of decimal places.
 *
 * Take for example the mass of the Earth in KG: 5970000000000000000000000
 * A number that large with many digits is hard on the eyes. But if we convert it to
 * scientific notation, we get: 5.97e^24
 * mantissa: 5.97
 * exponent: 24
 *
 */

int main()
{
    try {
       
        double d = 1234567.89;

        cout << "(defaultfloat)\t" << d << '\n'
             << "(fixed)\t" << fixed << d << '\n'
             << "(scientific)\t" << scientific << d << '\n';

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
