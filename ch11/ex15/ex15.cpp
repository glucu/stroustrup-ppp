#include "std_lib_facilities.h"

vector<double> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to read file, ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<double> data;
    for(double d; ifs >> d;) {
        data.push_back(d);
    }

    ifs.clear();

    return data;
}

void write_to_file(const vector<double> &data, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file ", name);

    ostringstream buffer;
    for(size_t i{}; i != data.size(); ++i) {
        if(i != 0 && i % 4 == 0) buffer << '\n';
        buffer << scientific << setprecision(8) << setw(20) << data[i];
        if(i != data.size() - 1) buffer << ' ';
    }

    ofs << buffer.str();
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

        vector<double> data = read_from_file(iname);
        write_to_file(data, oname);
         
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
