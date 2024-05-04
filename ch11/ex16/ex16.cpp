#include "std_lib_facilities.h"

/*
 * COMMENT:
 * I couldn't think of a function name for <b>func</b> :p
 */

vector<int> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to read file, ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<int> data;
    for(int val; ifs >> val;) {
        data.push_back(val);
    }

    ifs.clear();

    return data;
}

void write_to_file(ostringstream &buffer, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file ", name);

    ofs << buffer.str();
}

void func(vector<int> &data, const string &name)
{
    ostringstream buffer;
    if(data.size() == 0) error("func: no data read from file. size ", data.size()); 
    
    sort(data);
    size_t dup_cnt{1};
    size_t n = data.size();
    for(size_t i{1}; i != n; ++i) {
        if(data[i] == data[i-1]) ++dup_cnt;
        else {
            buffer << data[i-1];
            if(dup_cnt > 1) buffer << '\t' << dup_cnt;
            buffer << '\n';
            dup_cnt = 1;
        }
    }
    buffer << data[n-1];
    if(dup_cnt > 1) buffer << '\t' << dup_cnt;
    buffer << '\n';

    write_to_file(buffer, name);
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

        vector<int> data = read_from_file(iname);
        func(data, oname);

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
