/*
 * COMMENT:
 * This was one of the most headacne inducing experience I have ever experience. Of course, I could have slapped this poorly written, and
 * poorly indented code in an actual IDE and allow it to automatically indent it for me; however, because I am using vim and the fact
 * that I wanted to correct it myself without any help from an IDE. 
 */

struct X {
    void f(int x)
    {
        struct Y {
            int f() { return 1; }
            int m;
        };
        int m;
        m = x;
        Y m2;
        return f(m2.f());
    }
    
    int m;
    void g(int m) 
    {
        if(m) {
            f(m+2);
        }
        else {
            g(m+2);
        }
    }

    X() {}
    void m3() 
    {
    }
    void main()
    {
        X a;
        a.f(2);
    }
};


int main()
{

}
