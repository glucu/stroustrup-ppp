#include "std_lib_facilities.h"

class B1 {
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
};

int main()
{
    try {

        B1 b1{};
        b1.vf();
        b1.f();
        
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
