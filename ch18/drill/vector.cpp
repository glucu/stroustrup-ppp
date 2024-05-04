#include <iostream>
#include <vector>

std::vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void f(const std::vector<int> &vi)
{
    std::vector<int> lv(vi.size());
    lv = gv;
    for(int x : lv) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::vector<int> lv2(vi);
    for(int x : lv2) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
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
    f(gv);

    std::vector<int> vv;
    for(int i = 0; i != 10; ++i) {
        vv.push_back(fact(i));
    }

    f(vv);

    return 0;
}

