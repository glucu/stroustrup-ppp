#include "std_lib_facilities.h"

/*
 * COMMENT:
 * I intentionally left out the check of an overflow. Looks like exercise 4 deals with that
 */

void print(const vector<int> &v, const string &label)
// prints the sequence of fibonacci numbers
{
    cout << label << "\n{";
    for(int i = 0; i != v.size(); ++i) {
        if(i != 0 && i % 10 == 0) cout << '\n';
        cout << v[i];
        if(i != v.size() - 1) cout << ',';
    }
    cout << "}\n";
}

void fibonacci(int x, int y, vector<int> &v, int n)
// calculate the first n fibonacci number starting with x and y
// pre-condition: n is at least one
{
    if(n < 1) return;
    if(n >= 1) v.push_back(x);
    if(n >= 2) v.push_back(y);

    for(int i = 2; i < n; ++i) {
        int sum = x + y;
        x = y;
        y = sum;
        v.push_back(sum);
    }
}

int main()
{
    try {
        cout << "Please enter two integer values (to be used to start the fibonacci sequence) and a number "
             << "of elements of the series:\n";
        int x{}, y{}, n{};
        while(cin >> x >> y >> n) {
            vector<int> v;
            fibonacci(x,y,v,n);
            if(v.size() != 0) {
                print(v, "");
            }
            cout << "Enter again: ";
        }
         
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
