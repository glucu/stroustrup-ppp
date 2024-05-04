#include "std_lib_facilities.h"

vector<string> merge(const vector<string> &lhs, const vector<string> &rhs)
// merge the two sorted vectors into a third vector, preserving order
// pre-condition: return an empty vector if both inputs are empty
{
    if(lhs.size() == 0 && rhs.size() == 0) return {};

    vector<string> res;
    size_t lhs_len{lhs.size()}, rhs_len{rhs.size()};
    size_t i{}, j{}; 
    for(; i != lhs_len && j != rhs_len;) {
        if(lhs[i] <= rhs[j]) {
            res.push_back(lhs[i]);
            ++i;
        }
        else {
            res.push_back(rhs[j]);
            ++j;
        }
    }

    while(i != lhs_len) {
        res.push_back(lhs[i]);
        ++i;
    }

    while(j != rhs_len) {
        res.push_back(rhs[j]);
        ++j;
    }

    return res;
}

vector<string> read_from_file(const string &name) 
{
    ifstream ifs{name};
    if(!ifs) error("Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string word; ifs >> word;) {
        tmp.push_back(word);
    }

    // if(ifs.fail()) error("Unexpected read from file ", name);
    if(ifs.eof()) {
        ifs.clear();
        cout << "Completed reading " << tmp.size() << " words from "
             << "file " << name << "\n\n";
    }

    return tmp;
}

void write_to_file(const vector<string> &merge_words, const string &name)
{
    ofstream ofs{name};
    if(!ofs) error("Failed to open file ", name);
    
    for(size_t i{}; i != merge_words.size(); ++i) {
        ofs << merge_words[i];
        if(i != merge_words.size() - 1) ofs << ' ';
    }
}

int main()
{
    try {
       
        cout << "Enter first file name:\n";
        string iname1;
        cin >> iname1;

        cout << "Enter second file name:\n";
        string iname2;
        cin >> iname2;

        vector<string> words1 = read_from_file(iname1);
        vector<string> words2 = read_from_file(iname2);

        vector<string> merge_words = merge(words1, words2); 

        cout << "Please enter the output file name:\n";
        string oname;
        cin >> oname;

        write_to_file(merge_words, oname);

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
