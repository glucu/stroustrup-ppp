#include "std_lib_facilities.h"

/*
 * COMMENT:
 * The problem description was not as clear to me. I assume you enter a line (until newline is hit)
 * followed by a word. findx then searches for the word in that line. In other words, look up <b>std::strstr</b>
 * and the gist of it is to find a needle in the haystack. The implementation could be better, but i'll just with it
 * because it seems to work base on the inputs I gave it.
 *
 */

char* findx(const char *s, const char *x)
// return the first occurrence of x in s
// pre-condition: return NULL if s or x are nullptr
{
	if(!x || !s) return nullptr;

	for(size_t i{}; s[i]; ++i) {
		if(s[i] == x[0]) {
			size_t k{1};
			for(size_t j{i+1}; s[j] && x[k]; ++j) {
				if(s[j] != x[k]) break;
				++k;
			}
			if(!x[k]) {
				char *x_cpy = new char[k+1];
				for(size_t ii{i}, kk{}; x[kk]; ++ii, ++kk)
					x_cpy[kk] = s[ii];
				x_cpy[k] = '\0';
				return x_cpy;
			}
		}
	}
	return nullptr;
}

void ignore_line()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

const string kQuit{"q!"};

int main()
{
    try {

		cout << "Please enter the main string (s) followed by a substring "
			 << "to find (x) (Enter " << kQuit << " to quit):\n";
		while(true) {
			string haystack, needle;
			getline(cin, haystack);
			if(haystack == kQuit) break;
			cin >> needle;

			const char *s = haystack.c_str();
			const char *x = needle.c_str();

			char *result = findx(s,x);

			if(result) {
				cout << "substring " << result << " found in position " << (strstr(s, x) - s + 1) << '\n';
			}
			else {
				cout << "substring " << x << " not found in main string s.\n";
			}

			cout << "\nTry again:\n";

			delete[] result;
			ignore_line(); // to discard the newline cin leaves in the buffer
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
