#include "std_lib_facilities.h"

struct X { // simple test class
    int val;

    void out(const string &s, int nv) { cerr << this << "–>" << s << ": " << val << " (" << nv << ")\n"; }

    // default constructor
    X() {
        out("X()", 0);
        val = 0;
    }

    X(int v) {
        val = v;
        out("X(int)", v);
    }

    // copy constructor
    X(const X &x) {
        val = x.val;
        out("X(X&) ", x.val);
    }

    // copy assignment
    X &operator=(const X &a)
    {
        out("X::operator=()", a.val);
        val = a.val;
        return *this;
    }

    // destructor
    ~X() { out("~X()", 0); }
};

X glob(2); // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
    // local variable
    X loc {4};
    // copy construction
    X loc2 {loc};
    // copy assignment
    loc = X{5};
    // call by value and return
    loc2 = copy(loc);
    loc2 = copy2(loc);
    X loc3 {6};
    // call by reference and return
    X& r = ref_to(loc);
    delete make(7);
    delete make(8);
    // default values
    vector<X> v(4);
    XX loc4;
    // an X on the free store
    X* p = new X{9};
    delete p;
    // an array of Xs on the free store
    X* pp = new X[5];
    delete[] pp; 
}
