#include "std_lib_facilities.h"
/*
 * COMMENT:
 * I assume this exercise wants us to add up all "integers," regardless where they may be within strings?
 * Or is it strictly whitespace-separated integers with no characters adjacent to it either left or right?
 * I decided to add all integer values regardless if they are embedded within characters. Whether it is correct,
 * idk but I'll go with it.
 *
 */

int main()
{
    try {

        cout << "Enter file name to read:\n";
        string iname;
        cin >> iname;

        ifstream ifs{iname};
        if(!ifs) error("Failed to open file ", iname);

        int total{};
        while(!ifs.eof()) {
            double val{};
            if(!(ifs >> val)) {
                char ch{};
                ifs.clear();
                while(ifs >> ch && !isdigit(ch)) ; // null statement
                if(!ifs.eof())  ifs.putback(ch);

            }
            else {
                total += val;
            }
        }

        cout << "The sum of all the whitespace-separated integers in the text file "
             << iname << " is: " << total << '\n';

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
