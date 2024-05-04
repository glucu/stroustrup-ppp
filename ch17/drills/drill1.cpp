#include "std_lib_facilities.h"

/*
 * Drills 1-10
 */

void print_array10(ostream &os, const int *a)
{
    for(int i{}; i != 10; ++i) {
        os << a[i] << ' ';
    }
}

void print_array(ostream &os, const int *a, int n)
{
    for(int i{}; i != n; ++i) {
        os << a[i] << ' ';
    }
}

void print_vector(ostream &os, const vector<int> &vi) 
{
    for(auto x : vi) {
        os << x << ' ';
    }
}

int main()
{
    try {

        int *pa = new int[10]{};
        for(int i{}; i != 10; ++i) {
            cout << pa[i] << ' ';
        }
        cout << '\n';
        delete[] pa;

        pa = new int[10]{100,101,102,103,104,105,106,107,108,109};
        print_array10(cout, pa);
        cout << '\n';

        int *pa2 = new int[11]{100,101,102,103,104,105,106,107,108,109,110};
        print_array10(cout, pa2);
        cout << pa2[10] << '\n';

        print_array(cout, pa2, 11);
        cout << '\n';

        int *pa3 = new int[20]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
        print_array(cout, pa3, 20);
        cout << '\n';

        delete[] pa;
        delete[] pa2;
        delete[] pa3;


        // vectors
        vector<int> v1{100,101,102,103,104,105,106,107,108,109};
        print_vector(cout, v1);
        cout << '\n';

        vector<int> v2{100,101,102,103,104,105,106,107,108,109,110};
        print_vector(cout, v2);
        cout << '\n';

        vector<int> v3{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
        print_vector(cout, v3);
        cout << '\n';

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
