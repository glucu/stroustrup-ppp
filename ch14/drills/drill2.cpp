#include "std_lib_facilities.h"

class B1 {
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
};

class D1 : public B1 {
public:
    void vf() override { cout << "D1::vf()\n"; }
};

int main()
{
    try {

        D1 d1{};
        d1.vf();
        d1.f();

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
