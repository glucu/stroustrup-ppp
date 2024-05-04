#include "std_lib_facilities.h"

int main()
{
    try {

		int n{};
		if(cin >> n) {
			if(n < 0) error("negative number entered ", n);
			
			char *ca = new char[++n]{};
			ca[n] = 0;

			char ch{};
			for(int i{}; i != n && cin.get(ch) && ch != '!'; ++i) {
				if(isspace(ch)) ca[i] = ch;
				else            ca[i] = ch;
			}
			for(string s; cin >> s;) {
				cout << "What is left in the buffer: " << s << '\n';
				break;
			}

			cout << ca << '\n';
			delete[] ca;
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
