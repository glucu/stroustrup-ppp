#include "std_lib_facilities.h"

class B1 {
public:
    virtual void pvf() = 0;
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
};

class D1 : public B1 {
public:
    void vf() override { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

class D2 : public D1 {
public:
    void pvf() override { cout << "D2::pvf()\n"; }
};

int main()
{
    try {

        D2 d2{};
        d2.f();
        d2.vf();
        d2.pvf();

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
