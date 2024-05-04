#include "std_lib_facilities.h"

int main()
{
    try {
       
        cout << "Enter input file name:\n";
        string iname;
        cin >> iname;

        ifstream ifs{iname.c_str(), ios_base::binary};
        if(!ifs.is_open()) error("Failed to open file ", iname);

        ifs.exceptions(ifs.exceptions() | ios_base::badbit);

        for(char ch{}; ifs.read(as_bytes(ch), sizeof(char));) {
            cout << ch;
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
