#include "std_lib_facilities.h"

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> words;
    string word;
    while(ifs >> word) words.push_back(word);

    ifs.clear();

    return words;
}

void write_to_file(const vector<string> &words, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file for writing ", name);

    for(const string &w : words) {
        ofs << w << ' ';
    }
}

void reverse(vector<string> &words)
{
    size_t n = words.size();
    for(size_t i{}; i != n/2; ++i) {
        swap(words[i], words[n-i-1]);
    }
}

int main()
{
    try {

        cout << "Please enter input file name:\n";
        string iname;
        cin >> iname;

        cout << "Please enter output file name:\n";
        string oname;
        cin >> oname;

        vector<string> words = read_from_file(iname);
        reverse(words);
        write_to_file(words, oname);

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
