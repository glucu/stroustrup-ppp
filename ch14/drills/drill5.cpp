#include "std_lib_facilities.h"

/*
 * COMMENT:
 * error: cannot declare variable ‘b1’ to be of abstract type ‘B1’
 *   21 |         B1 b1{};
 *
 * B1 is now an abstract class (it declared at least one pure virtual function)
 * Therefore you cannot create an instance of that class.
 *
 *
 */

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

int main()
{
    try {
        
        // B1 b1{};

        /* d1 does not override the pure function in class B1. It is also an abstract class and will
         * be the same problem as the object b1 of type B1.
        D1 d1{};
        d1.vf();
        d1.f();
        */

        // B1 &b1r = d1; Will not work when d1 is an abstract class and thus cannot create an object in the first place.

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
