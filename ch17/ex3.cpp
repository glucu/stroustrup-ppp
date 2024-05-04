#include "std_lib_facilities.h"

const string kQuit{"q!"};

void to_lower(char *s) 
// convert the uppercase characters in s
// to its lowercase equivalents
// pre-condition: s is not a nullptr 
{
    if(!s) return;

    for(char *sp{s}; *sp; ++sp) {
        char &ch{*sp};
        if(ch >= 'A' && ch <= 'Z') 
            ch = ch + 32;
    }
}

int main()
{
    try {

        for(string s; getline(cin, s) && s != kQuit;) {
            char *ca = &s[0];
            cout << "Input:\t" << s << '\n';
            to_lower(ca);
            cout << "Output:\t" << s << '\n';
        }

        return 0;
    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
