#include "std_lib_facilities.h"

string read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    string s;
    ifs >> s;

    cin.clear();

    return s;
}

void write_to_file(const string &s, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file for writing ", name);

    ofs << s << '\n';
}

void reverse(string &s)
{
    size_t n = s.size();
    for(size_t i{}; i != n/2; ++i) {
        swap(s[i], s[n-i-1]);
    }
} 

int main()
{
    try {
       
        cout << "Please enter input file name:\n";
        string iname;
        cin >> iname;

        cout << "Please enter output file name:\n";
        string oname;
        cin >> oname;

        string input = read_from_file(iname);
        reverse(input);
        write_to_file(input, oname);

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
