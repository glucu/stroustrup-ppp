#include "std_lib_facilities.h"

void write_to_file(vector<string> &lines, const string &name)
{
    ofstream ofs{name};
    if(!ofs) error("Failed to open file for writing ", name);

    for(const string &line : lines) {
        ofs << line << '\n';
    }
}

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name};
    if(!ifs) error("Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string line; getline(ifs, line);) {
        tmp.push_back(line);
    }

    ifs.clear();

    return tmp;
}

void to_lower(vector<string> &lines)
// convert all words to lowercase
// pre-condition: size must be at least one

{
    if(lines.size() == 0) return;

    for(string &s : lines) {
        for(char &c : s) {
            c = tolower(c);
        }
    }
}

int main()
{
    try {
       
        cout << "Enter the input file name:\n";
        string iname;
        cin >> iname;

        vector<string> lines = read_from_file(iname);
        to_lower(lines);

        cout << "Enter output file name:\n";
        string oname;
        cin >> oname;
        write_to_file(lines, oname);

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
