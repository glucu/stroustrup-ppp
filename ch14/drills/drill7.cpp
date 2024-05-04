#include "std_lib_facilities.h"

class B2 {
public:
    virtual void pvf() = 0;
};

class D21 : public B2{
public:
    string s;
    void pvf() override { cout << "D21::pvf() " << s << '\n'; };
};

class D22 : public B2 {
public:
    int i;
    void pvf() override { cout << "D22::pvf() " << i << '\n'; };
};

void f(B2 &b) 
{
    b.pvf();
}

int main()
{
    try {

        D21 d21{};
        d21.s = "string literal";
        D22 d22{};
        d22.i = 27;

        f(d21);
        f(d22);

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
