#include "std_lib_facilities.h"

vector<string> names;
vector<int> scores;

bool is_duplicate(const string &name)
{
    for(string n : names) {
        if(n == name) return true;
    }
    return false;
}

void get_name_value_pairs() 
{
    string name;
    int score{};
    while(true) {
        cout << "Enter name: ";
        cin >> name;
        if(is_duplicate(name)) {
            cout << name << " already exists. Try again.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter score for " << name << ": ";
            cin >> score;
            if(cin) {
                if(name == "NoName" && score == 0) return;

                names.push_back(name);
                scores.push_back(score);
            }
            else {
                if(cin.eof()) error("EOF reached");
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "What you read for score was not an integer. Try again.\n";
            }
        }
    }
}

void print_name_value_pairs()
{
    cout << "Here are the name-value pairs you have entered:\n";
    for(size_t i{}; i != names.size(); ++i) {
        cout << '(' << names[i] << ',' << scores[i] << ")\n";
    }
}

int main()
{
    try {
       
        cout << "Please enter a series of name-and-value pairs. Enter \'NoName 0\' to stop.\n";
        get_name_value_pairs();

        print_name_value_pairs();

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
