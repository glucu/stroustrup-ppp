#include "std_lib_facilities.h"

class Name_value
{
public:
    Name_value() : name{}, value{} {}
    Name_value(const string &n, int v) : name{n}, value{v} {}

string name;
int value;
};

int main()
{
    try {
       
        cout << "Please enter a name-value pair seperated by a space (followed by \'NoName 0\' to quit): \n";
        vector<Name_value> pairs;
        string name;
        int value;
        while(cin >> name >> value && name != "NoName" && value != 0) {
            pairs.push_back({name, value});
        }

        for(int i = 0; i != pairs.size(); ++i) {
            cout << '(' << pairs[i].name << ',' << pairs[i].value << ")\n";
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
