#include "std_lib_facilities.h"

const string kQuit{"q!"};

char* strdup(const char *s)
// copy the contents of s in memory 
// and return a copy of it
// pre-condition: return nullptr if s is a NULL pointer
{
	if(!s) return nullptr;

	size_t n{};
	while(s[n]) ++n;

	char *s_cpy = new char[n+1];

	n = 0;
	while(s[n]) {
		s_cpy[n] = s[n];
		++n;
	}

	s_cpy[n] = '\0';

	return s_cpy;
}

int main()
{
    try {
       
        for(string s; getline(cin, s) && s != kQuit;) {
			cout << "Input:\t" << s << '\n';
			char *s_cpy = strdup(s.c_str());
			cout << "Output:\t" << s_cpy << '\n';
			delete[] s_cpy;
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
