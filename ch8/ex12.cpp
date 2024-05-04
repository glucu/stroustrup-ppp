#include "std_lib_facilities.h"

/*
 * COMMENT:
 * Improvements:
 * 1. pass both v and quit by const-reference
 * 2. mark s as a const-reference to avoid copying
 * 3. the name <b>print_until_s</b> is a bit ambiguous. Rename to <b>print_until_quit</b>
 *
 * Good Test cases:
 * 1. Test with an empty vector and strings
 * 2. Test with just a single element in the vecotor
 * 3. Test base on an even or odd number of elements in the vector
 * 4. Test where vector does not contain the quit string
 *
 */

void print_until_ss(const vector<string> &v, const string &quit)
{
    int cnt = 0;
    for(string s : v) {
        if(s != quit)
            cout << s << '\n';
        else {
            if(++cnt == 2) return;
        }
    }
}

void print_until_s(const vector<string> &v, const string &quit)
{
    for(const string &s : v) {
        if(s == quit) return;
        cout << s << '\n';
    }
}

vector<string> get_data()
{
    vector<string> tmp;
    for(string s; cin >> s && s != "q!";) {
        tmp.push_back(s);
    }
    return tmp;
}

int main()
{
    try {
       
        cout << "Please enter a number of strings (followed by \'q!\' to quit):\n";
        vector<string> test_data = get_data();
        string quit = "quit";
        print_until_s(test_data, quit);
        cout << '\n';
        print_until_ss(test_data, quit);

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
