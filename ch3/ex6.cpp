#include "std_lib_facilities.h"

// There are 3! (3 * 2 * 1) ways to enter three integers as input. A
// permutation of 3 is 6 possible solutions.
//    {a, b, c}
//    {a, c, b}
//    {b, a, c}
//    {b, c, a}
//    {c, a, b}
//    {c, b, a}

// I think this program can scale well if you need to add an additional variable. For n variables, the number of comparisons needed is roughly proportional to n*(n-1)/2.
// Of course, there's better ways to make this far more efficient and easier to read. The book will introduce better solutions: vector.

int main()
{
    try {
        
        cout << "Please enter three integers seperated by a space (followed by a non-integer character to quit):\n";
        int val1 = 0;
        int val2 = 0;
        int val3 = 0;
        while(cin >> val1 >> val2 >> val3) {
            if(!cin) error("something went wrong with the read");
            cout << "Values entered: " << val1 << ' ' << val2 << ' ' << val3 << '\n';

            int tmp{-1};
            if(val1 > val2) {
                tmp = val1;
                val1 = val2;
                val2 = tmp;
            }

            if(val2 > val3) {
                tmp = val2;
                val2 = val3;
                val3 = tmp;

                if(val1 > val2) {
                    tmp = val1;
                    val1 = val2;
                    val2 = tmp;
                }
            }

            cout << "Values Sorted: " << val1 << ',' << val2 << ',' << val3 << "\n\n";
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
