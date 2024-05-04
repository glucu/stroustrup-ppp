#include "std_lib_facilities.h"

vector<string> split(const string &s)
{
    istringstream iss{s};
    vector<string> substrings;
    for(string word; iss >> word;) {
        substrings.push_back(word);
    }
    return substrings;
}

void print_substrings(const vector<string> &substrings)
{
    for(const string &s : substrings) {
        cout << s << ' ';
    }
    cout << '\n';
}

int main()
{
    try {
        const string kQuit{"q!"};

        cout << "Enter a series of strings and I will display its substrings:\n";
        for(string input; getline(cin, input) && input != kQuit;) {
            vector<string> substrings = split(input);
            cout << "You entered: " << input << "\n\n"
                 << "Here are the substrings: ";
            print_substrings(substrings);
            cout << "Enter again (or \'q!\' to quit):\n";
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
