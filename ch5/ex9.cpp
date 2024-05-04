#include "std_lib_facilities.h"

int read_n()
// read n for the sum of the first n integers
{
    while(true) {
        int n = 0;
        cin >> n;
        if(cin && n > 0) {
            return n;
        }
        else if(n <= 0) {
            cout << n << " must be a positive integer\n";
        }
        else {
            if(cin.eof()) error("EOF reached");
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive integer\n";
        }
    }
}

vector<int> read_values()
// read a sequence of integers and return a vector
{
    vector<int> values;
    for(int value; cin >> value;) {
        values.push_back(value);
    }
    return values;
}

int main()
{
    try {
        cout << numeric_limits<int>::max() << '\n'; 
        cout << "Please enter the number of values you want to sum: ";
        int n = read_n();

        cout << "Please enter some integers (press \'|\' to stop):\n";
        vector<int> values = read_values();

        if(n > values.size()) error("The value of n is greater then the size of the sequence");

        int sum = 0;
        for(int i = 0; i != n; ++i) {
            if(values[i] > 0 && sum > numeric_limits<int>::max() - values[i])
                error("integer overflow occurred!");
            else if(values[i] < 0 && sum < numeric_limits<int>::min() - values[i])
                error("integer underflow occurred!");
            sum += values[i];
        }

        cout << "The sum of the first " << n << " numbers ( ";
        for(int i = 0; i != n; ++i) {
            cout << values[i] << ' ';
        }
        cout << ") is " << sum << ".\n";

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
