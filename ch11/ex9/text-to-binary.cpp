#include "std_lib_facilities.h"

int main()
{
    try {
       
        cout << "Enter the input text file:\n";
        string iname;
        cin >> iname;

        cout << "Enter the output binary file:\n";
        string oname;
        cin >> oname;

        ifstream ifs{iname.c_str()};
        if(!ifs) error("Failed to read file ", iname);

        ifs.exceptions(ifs.exceptions() | ios_base::badbit);

        ofstream ofs{oname.c_str(), ios_base::binary};

        char ch{};
        while(ifs.get(ch)) {
            ofs.write(as_bytes(ch), sizeof(char));
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
