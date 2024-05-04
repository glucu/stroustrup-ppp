#include "std_lib_facilities.h"

vector<string> split1(const string &s)
{
    istringstream iss{s};
    vector<string> substrings;
    for(string word; iss >> word;) {
        substrings.push_back(word);
    }
    return substrings;
}

string parse_substring(const string &word, const string &w)
{ 
    string res = word;
	for(char &c1 : res) {
		for(char c2 : w) {
			if(c1 == c2) c1 = ' ';
		}
	}
	return res;
}

bool contains(char c, const string &w)
{
	for(char wc : w) {
		if(c == wc) return true;
	}
	return false;
}

vector<string> split2(const string &s, const string &w)
{
	string res = s;
	for(char &ch : res) {
		if(contains(ch, w)) ch = ' ';
	}

	return split1(res);
}

void ignore_line()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void print(const vector<string> &substrings)
{
	for(const string &s : substrings) {
		cout << s << ' ';
	}
}

int main()
{
    try {
		const string kQuit{"q!"};

		cout << "Please enter a string (followed by \'Enter\' key) and a set of additional characters for custom whitespace,\n"
             << "and I will split the string into substrings using ordinary whitespace and the provided characters:\n\n> ";
	    for(string s, w; getline(cin, s) && s != kQuit && cin >> w;) {
			ignore_line();
		  
		    vector<string> substrings = split2(s, w);

		    print(substrings);

			cout << "\nEnter again (or \'q!\' to quit):\n> ";
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
