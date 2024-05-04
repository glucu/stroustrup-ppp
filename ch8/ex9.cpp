#include "std_lib_facilities.h"

double calculate_weighted_sum(const vector<double> &u, const vector<double> &v)
// calculates the sum of all u[i] * v[i]
// pre-condition: the size of both u and v must be equal
{
    if(u.size() != v.size()) error("vector must have the same size");

    double sum{};
    for(size_t i = 0; i != u.size(); ++i) {
        sum += u[i] * v[i];
    }
    return sum;
}

int main()
{
    try {

        vector<double> u{1,2,3,4};
        vector<double> v{1,2,3,4};

        cout << calculate_weighted_sum(u,v) << '\n';

        u = {1,2};
        v = {1};
        
        // this will fail
        cout << calculate_weighted_sum(u,v) << '\n';

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
