#include "std_lib_facilities.h"

string process_classification(char ch)
{
    string res;
    if(isspace(ch)) res += "isspace ";
    if(isalpha(ch)) res += "isalpha ";
    if(isdigit(ch)) res += "isdigit ";
    if(isxdigit(ch)) res += "isxdigit ";
    if(isupper(ch)) res += "isupper ";
    if(islower(ch)) res += "islower ";
    if(isalnum(ch)) res += "isalnum ";
    if(iscntrl(ch)) res += "iscntrl ";
    if(ispunct(ch)) res += "ispunct ";
    if(isprint(ch)) res += "isprint ";
    if(isgraph(ch)) res += "isgraph ";
    
    return res;
}

const string kStop{"stop"};

int main()
{
    try {
       
        for(string word; cin >> word && word != kStop;) {
            for(char ch : word) {
                string res = process_classification(ch);
                cout << "The character " << ch 
                     << " character classifications are: " << res << '\n';
            }
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
