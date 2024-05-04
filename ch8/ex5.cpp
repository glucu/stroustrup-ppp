#include "std_lib_facilities.h"

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

vector<int> reverse_1(const vector<int> &values)
// reverses the elements of values out-of-place
// This requires O(n) memory space
{
    int n = values.size();
    vector<int> result;
    for(int i = 0; i < n; ++i) {
        result.push_back(values[n - i - 1]);
    }
    return result;
}

void reverse_2(vector<int> &values)
// reverses the elements of values in-place
// This requires O(1) memory space
{
    int n = values.size();
    for(int i = 0; i < n/2; ++i) {
        swap(values[i], values[n - i - 1]);
    }
}

int main()
{
    try {
       
        vector<int> values;
        cout << "Enter a series of integers seperated by a space (followed by a non-digit to stop):\n";
        for(int value; cin >> value;) {
            values.push_back(value);
        }

        vector<int> v1 = reverse_1(values);
        print(v1, "reverse_1 ");
        reverse_2(values);
        print(values, "reverse_2");
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
