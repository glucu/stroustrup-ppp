#include "std_lib_facilities.h"

int maxv(const vector<int> &v)
// return the largest element in v
// pre-condition: v size must be at least one
{
    if(v.size() == 0) error("v size must be at least one");

    int max = v[0];
    for(int x : v) {
        if(x > max) max = x;
    }
    return max;
}

int main()
{
    try {
        
        vector<int> v{1,2,3,4,5,6,7,8,9};
        cout << maxv(v) << '\n';

        v = {9,8,7,6,5,4,3,2,1};
        cout << maxv(v) << '\n';

        v = {1};
        cout << maxv(v) << '\n';

        v = {};
        cout << maxv(v) << '\n';

        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
