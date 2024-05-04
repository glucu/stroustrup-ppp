#include "std_lib_facilities.h"

/*
 * Drills 11-23
 */

void print_array(ostream &os, const int *a, int n)
{
    for(int i{}; i != n; ++i) {
        os << a[i] << ' ';
    }
}

int main()
{
    try {

        int *p1 = new int{7};
        cout << "p1 == " << p1 << " *p1 == " << *p1 << '\n';

        int *p2 = new int[7]{1,2,4,8,16,32,64};
        cout << "p2 == " << p2 << ' ';
        print_array(cout, p2, 7);
        cout << '\n';

        int *p3 = p2;
        delete p1;
        p1 = p2; 
        p3 = p2;
        p2 = nullptr;
        cout << "p1 == " << p1 << " p2 == " << p2 << '\n';
        
        delete[] p1;

        p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
        p2 = new int[10]{};
        for(int i{}; i != 10; ++i) {
            p2[i] = p1[i];
        }
        print_array(cout, p2, 10);
        cout << '\n';

        delete[] p1;
        delete[] p2;

        vector<int> v1{1,2,4,8,16,32,64,128,256,512};
        vector<int> v2(10);
        v2 = v1;

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
