#include <iostream>

int ga[]{1,2,4,8,16,32,64,128,256,512};

void f(const int ai[], int n)
{
    int la[10];
    for(int i = 0; i != 10; ++i) {
        la[i] = ga[i];
    }
    for(int i = 0; i != 10; ++i) {
        std::cout << la[i] << ' ';
    }
    std::cout << '\n';

    int *p = new int[n];
    for(int i = 0; i != n; ++i) {
        p[i] = ai[i];
    }
    for(int i = 0; i != n; ++i) {
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';

    delete[] p;
}

int fact(int n)
{
    if(0 < n) {
        return n * fact(n-1);
    }
    return 1;
}

int main()
{
    f(ga, 10);

    int aa[10];
    for(int i = 0; i != 10; ++i) {
        aa[i] = fact(i);
    }

    f(aa, 10);

    return 0;
}
