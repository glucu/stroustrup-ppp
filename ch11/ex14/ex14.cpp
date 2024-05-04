#include "std_lib_facilities.h"

/*
 * COMMENT:
 * I stole the code for exercise 5. Reusing existing code to serve a new purpose whenever possible
 * is always feasible. I read from the file, did the needed computation and outputted to stdIn (console)
 * instead of writing it to a new file. I chose to use two parallel vectors in the global scope (okay when -
 * classif is const) but counts isn't but the problem isn't a complex one with many files where it can be a
 * problem. parse_data() most likely can be split to reduce the clutter, but I
 * will leave it as that. Output formatting is also tricky because you don't know what is considered "good"
 * formatting when many people have different needs and tastes. That's all for now :)
 */

const vector<string> classif{"space", "alpha", "digit", "xdigit", "upper",
                             "lower", "alnum", "cntrl", "punct", "print", "graph"};
vector<size_t> counts(classif.size(),0);

string process_classification(char ch)
{
    string res;
    if(isspace(ch)) res += "space ";
    if(isalpha(ch)) res += "alpha ";
    if(isdigit(ch)) res += "digit ";
    if(isxdigit(ch)) res += "xdigit ";
    if(isupper(ch)) res += "upper ";
    if(islower(ch)) res += "lower ";
    if(isalnum(ch)) res += "alnum ";
    if(iscntrl(ch)) res += "cntrl ";
    if(ispunct(ch)) res += "punct ";
    if(isprint(ch)) res += "print ";
    if(isgraph(ch)) res += "graph ";
    
    return res;
}

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to read file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> data;
    for(string line; getline(ifs, line);) {
        data.push_back(line);
    }

    ifs.clear();

    return data;
}

void parse_data(const vector<string> &data)
{
    for(const string &word : data) {
        for(char ch : word) {
            string buffer = process_classification(ch);
            istringstream iss{buffer};
            for(string w; iss >> w;) {
                for(size_t i{}; i != classif.size(); ++i) {
                    if(classif[i] == w) counts[i]++;
                }
            }
        }
    }
}

void print()
{
    cout << "\nSTATISTICS:\n\n";
    for(size_t i{}; i != classif.size(); ++i) {
        cout << classif[i] << ": " << counts[i] << '\n';
    }
}

int main()
{
    try {

        cout << "Please enter input file name:\n";
        string iname;
        cin >> iname;

        vector<string> data = read_from_file(iname);

        parse_data(data);

        print();

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
