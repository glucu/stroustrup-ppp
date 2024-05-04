#include "std_lib_facilities.h"

/*
 * COMMENT:
 * Every function should do only one logical thing and it should do it well. A function should do one
 * logical computation. If you have two distinct computations, split it into different functions. I chose
 * three functions for the sizes an longest/shortest strins. I could have written another function for
 * computing the lexico first and last, but I thought it was easy so I added it to the calculate() function
 * instead. 
 */

struct Stats {
    vector<int> sizes;
    string min;
    string max;
    string lexi_first;
    string lexi_last;
};

vector<int> get_sizes(const vector<string> &vs) 
// return a vector containing the length of each
// string in vs
{
    vector<int> tmp;
    for(const string &s : vs) {
        tmp.push_back(s.size());
    }
    return tmp;
}

string longest(const vector<string> &vs) 
// return the string that contains the most characters
{
    size_t max = 0;
    for(size_t i = 0; i != vs.size(); ++i) {
        if(vs[i].size() > vs[max].size()) max = i;
    }
    return vs[max];
}

string shortest(const vector<string> &vs)
// return the string that contains the least characters
{
    size_t min = 0;
    for(size_t i = 0; i != vs.size(); ++i) {
        if(vs[i].size() < vs[min].size()) min = i;
    }
    return vs[min];
}

Stats calculate(const vector<string> &vs)
{
    if(vs.size() == 0) error("Calculate: empty container");
    vector<string> tmp(vs);
    Stats stats;
    stats.sizes = get_sizes(tmp);
    stats.min = longest(tmp);
    stats.max = shortest(tmp);

    sort(tmp);
    stats.lexi_first = tmp[0];
    stats.lexi_last = tmp[tmp.size()-1];

    return stats;
}

void print_stats(const Stats &stats)
{
    cout << "STATISTICS:\n"
         << "sizes: ";
    for(const int &x : stats.sizes) cout << x << ' ';
    cout << '\n'
         << "longest:\t" << stats.min << '\n'
         << "shortest:\t" << stats.max << '\n'
         << "lexico first:\t" << stats.lexi_first << '\n'
         << "lexico last:\t" << stats.lexi_last << '\n';
}

const string quit = "|";

int main()
{
    try {
       
        cout << "Please enter a series of strings separated by a space (followed by " << quit << " to stop):\n";
        vector<string> vs;
        for(string s; cin >> s && s != quit;) {
            vs.push_back(s);
        }

        Stats stats = calculate(vs);

        print_stats(stats);

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
