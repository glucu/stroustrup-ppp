#include "std_lib_facilities.h"

int main()
{
    try {
       
		string s;
        for(char ch; cin >> ch && ch != '!';) {
			s.push_back(ch);
		}	

		cout << s << '\n';

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
