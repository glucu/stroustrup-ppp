#include "std_lib_facilities.h"

constexpr int max_names{5};

bool is_in(const vector<string> &n, const string &s)
// Checks if s is in n already
{
    for(string x : n) {
        if(x == s) return true;
    }
    return false;
}

int get_age() 
// read in a age 
{
    while(true) {
        int a{};
        cin >> a;
        if(!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Sorry, that is not a digit. Try again:\n";
        }
        else {
            if(a > 0) return a;
            cout << a << " is a negative age. Try again: \n";
        }
    }
}

void read_name_age_pairs(vector<string> &names, vector<int> &ages)
// read five names followed by the ages of those names
{
    cout << "Please enter " << max_names << " names separated by a space:\n";
    for(int i = 0; i != max_names; ++i) {
        string name;
        cin >> name;
        if(!is_in(names, name)) {
            names.push_back(name);
        }
        else {
            cout << name << " already exists. Please try again.\n";
            --i;
        }
    }

    for(int i = 0; i != names.size(); ++i) {
        cout << "Now, enter the age for " << names[i] << ": ";
        int age = get_age();
        ages.push_back(age);
    }
}

int find_index(const string &n, const vector<string> &nc)
// returns index that coressponds the age for n if found;
// otherwise an error occurs if name was not found
{
    for(int i = 0; i != nc.size(); ++i) {
        if(n == nc[i]) return i;
    }
    error(n, " was not found");
}

void print(const vector<string> &names, const vector<int> &ages, const string &label)
// print the (name,age) pairs
{
    cout << label << ": \n";
    for(int i = 0; i != names.size(); ++i) {
        cout << '(' << names[i] << ',' << ages[i] << ")\n";
    }
    cout << '\n';
}

int main()
{
    try {
       
        vector<string> names;
        vector<int> ages;
        read_name_age_pairs(names, ages);
        print(names, ages, "(Name,Age) entered");

        vector<string> name_copies = names;
        vector<int> age_copies = ages;
        sort(names);
        for(int i = 0; i != names.size(); ++i) {
            int idx = find_index(names[i], name_copies);
            age_copies[i] = ages[idx];
        }
        ages = age_copies;

        print(names, ages, "(Name,Age) sorted)");

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
