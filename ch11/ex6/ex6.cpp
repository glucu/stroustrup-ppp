#include "std_lib_facilities.h"

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to read from file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string line; getline(ifs, line);) {
        tmp.push_back(line);
    }

    cin.clear();

    return tmp;
}

void write_to_file(const vector<string> &lines, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file for write ", name);

    for(const string &line : lines) {
        ofs << line << '\n';
    }
}

const string puncts{".;,?-'"};

bool is_punct(char ch)
{
    for(const char &p : puncts) {
        if(ch == p) return true;
    }
    return false;
}

void remove_punct(vector<string> &lines) 
{
    for(string &line : lines) {
        int quote{};
        for(char &ch : line) {
            if(ch == '"') {
                ++quote;
                if(quote == 2) quote = 0;
            }
            if(!quote && is_punct(ch)) ch = ' ';
        }  
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

        vector<string> lines{ read_from_file(iname) };
        remove_punct(lines);
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
