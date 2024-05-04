#include "std_lib_facilities.h"

void sizes(char ch, int i, int *p, bool b, double d, long double dd, short s, long l, long long ll,  double *pd)
{
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n'
         << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n'
         << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n'
         << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n'
         << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n'
         << "the size of long double is " << sizeof(long double) << ' ' << sizeof(dd) << '\n'
         << "the size of double* is " << sizeof(double*) << ' ' << sizeof(pd) << '\n'
         << "the size of short is " << sizeof(short) << ' ' << sizeof(s) << '\n'
         << "the size of long is " << sizeof(long) << ' ' << sizeof(l) << '\n'
         << "the size of long long is " << sizeof(long long) << ' ' << sizeof(ll) << '\n';
}

int main()
{
    try {
       
        char ch{};
        int i{};
        int *pi = &i;
        bool b{};
        double d{};
        long double dd{};
        short s{};
        long l{};
        long long ll{};
        double *pd = &d;
        sizes(ch, i, pi, b, d, dd, s, l, ll, pd);

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
