#include "std_lib_facilities.h"

void print(const vector<int> &sample, const string &label) 
// prints a label followed by the elements of the vector iv
// pre-condition: iv must be at least of size 1
{
    if(sample.size() == 0) return; 
    
    cout << label << ":\n{";
    for(int i = 0; i != sample.size(); ++i) {
        if(i != 0 && i % 10 == 0) cout << '\n';
        cout << sample[i];
        if(i != sample.size() - 1) cout << ',';
    }
    cout << "}\n"; 
}

int main()
{
    try {

        vector<int> sample;
        const string label{"Sample data"};

        for(int i = 0; i != 100; ++i) {
            sample.push_back(i);
        }

        print(sample, label);

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
