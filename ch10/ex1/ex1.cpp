#include "std_lib_facilities.h"

/*
 * COMMENT:
 * This is a simple exercise, yet the choice of modularity is preferred.
 * I like to keep in mind the phrase: "if a computation is worthy of a name,
 * make it into a function." This is what I went with.
 */

class Range_handler {   // object to throw if an overflow occurrs
public:
    Range_handler(int sum) : m_sum{sum} {}

    int m_sum{};
};

vector<int> read_from_file(const string &name)
// read in a series of white-space separated integers
{
    ifstream ist{name};
    if(!ist) error("Failed to open file ", name);

    vector<int> tmps;
    for(int val; ist >> val;) {
        tmps.push_back(val);
    }

    if(ist.eof()) {
        ist.clear();
        cout << "Completed reading from file " << name << " and "
             << "read " << tmps.size() << " integers.\n";
    }
    if(ist.fail()) error("file is not well formatted ", name);
    return tmps;
}

bool check_add(int x, int y)
// adds to values and checks if an overflow occurs, if so, return false
// otherwise return true
{
    if(((y > 0) && (x > (numeric_limits<int>::max() - y))) ||
       ((y < 0) && (x < (numeric_limits<int>::min() - y)))) {
        return true;
    }

    return false;
}

int compute_sum(const vector<int> &values)
// compute the sum of integers in values
// checks for potential overflow
// pre-condition: size of values must be at least one
{
    if(values.size() == 0) return 0;

    int sum{values[0]};
    for(size_t i{1}; i != values.size(); ++i) {
        if(check_add(sum, values[i])) throw Range_handler{sum};
        sum += values[i];
    } 
    return sum;
} 

void run()
{
    try {
        cout << "Please enter input file name:\n";
        string iname;
        cin >> iname;

        vector<int> values = read_from_file(iname);
        int sum = compute_sum(values);

        cout << "The sum of the values is " << sum << '\n';
                
    }
    catch(const Range_handler &e) {
        cerr << "Range error: Here is what I was able to compute before an overflow: "
             << e.m_sum << '\n';
        return;
    }
}

int main()
{
    try {

        run(); 

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
