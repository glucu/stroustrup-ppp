#include "std_lib_facilities.h"

bool is_vowel(char c) 
// is c a vowel letter?
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || 
           c == 'o' || c == 'u';
}

bool is_whitespace(char ch)
// is ch a whitespace?
{
    return ch == ' ' || ch == '\n' ||
           ch == '\t';
}

void remove_vowels(vector<string> &lines)
// disemvowel all vowels, dealing with potential
// double spacing or more
{
    for(string &line : lines) {
        string new_line;
        bool is_prev_white{};
        for(char ch : line) {
            if(!is_vowel(ch))  {
                if(is_whitespace(ch)) {
                    if(!is_prev_white) {
                        new_line += ' ';
                        is_prev_white = true;
                    }
                }
                else {
                    new_line += ch;
                    is_prev_white = false;
                }
            }
        }

        line = new_line;
    }
}

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs.is_open()) error("read_from_file: Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string line; getline(ifs, line);) {
        tmp.push_back(line);
    }

    ifs.clear();

    return tmp;
}

void write_to_file(const vector<string> &lines, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs.is_open()) error("write_to_file: Failed to open file for write ", name);

    for(const string &line : lines) {
        ofs << line << '\n';
    }
}

int main()
{
    try {

        cout << "Enter input file name:\n";
        string iname;
        cin >> iname;

        cout << "Enter output file name:\n";
        string oname;
        cin >> oname;

        vector<string> lines = read_from_file(iname);
        remove_vowels(lines);
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
