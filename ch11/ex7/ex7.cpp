#include "std_lib_facilities.h"

/* 
 * COMMENT:
 * I did not think the <b>check_hyphen</b> function would be this difficult.
 * I am not so happy with this solution. I spent too much time on it and will move on.
 */

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name.c_str()};
    if(!ifs) error("read_from_file: Failed to read from file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string line; getline(ifs, line);) {
        tmp.push_back(line);
    }

    cin.clear();

    return tmp;
}

void write_to_file(const vector<string> &lines, const string &name)
{
    ofstream ofs{name.c_str()};
    if(!ofs) error("write_to_file: Failed to open file for write ", name);

    for(const string &line : lines) {
        ofs << line << '\n';
    }
}

string& to_lower(string &line) 
{
    for(char &ch : line) {
        if(isalpha(ch)) ch = tolower(ch);
    }
    return line;
}

string& find_and_replace(string &line)
{
    static const vector<string> words_to_replace{"don't", "can't"};
    static const vector<string> replace_words{"do not", "cannot"}; 

    istringstream buffer(line);
    ostringstream oss;
    for(string word; buffer >> word;) {
        for(size_t i{}; i != words_to_replace.size(); ++i) {
            if(word == words_to_replace[i]) word = replace_words[i];
        }
        oss << word << ' '; 
    }

    line = oss.str();
    return line; 
}

bool is_punct(char ch)
{
    static const string puncts{".;,?-'"};
    for(const char &p : puncts) {
        if(ch == p) return true;
    }
    return false;
}

void remove_trailing_hyphens(string &word)
{
    for(size_t i{}, n{word.size()}; i != n && word[n-i-1] == '-'; ++i) {
        word[n-i-1] = ' ';
    }
}


void remove_leading_hyphens(string &word)
{
    for(size_t i{}; i != word.size() && word[i] == '-'; ++i) {
        word[i] = ' ';
    }
}

bool check_hyphen(string &word)
{
    bool is_found{};
    for(const char &ch : word) if(ch == '-') is_found = true;
    if(!is_found) return false;

    remove_leading_hyphens(word);
    remove_trailing_hyphens(word);

    bool is_prev_letter{};
    bool is_hyphen{};
    for(size_t i{}; i != word.size(); ++i) {
       char &c = word[i];
        if(isalpha(c)) {
            is_prev_letter = true;
            is_hyphen = false;
        }
        else if(c == '-') {
            if(is_hyphen && !is_prev_letter) return false;
            is_hyphen = true;
        }
        
    }

    return !is_hyphen || (is_hyphen && is_prev_letter);
}



void remove_punct(vector<string> &lines) 
{
    for(string &line : lines) {
        line = to_lower(line);
        line = find_and_replace(line);

        int quote{};
        istringstream iss{line};
        line = "";
        
        for(string word; iss >> word;) {
            if(!check_hyphen(word)) {
                for(char &ch : word) { 
                    if(ch == '"') {
                        ++quote;
                        if(quote == 2) quote = 0;
                    }
                    if(!quote && is_punct(ch)) ch = ' ';
                }  
            }
            line += word + ' ';
        }
    }
}

int main()
{
    try {
       
        cout << "Enter input file name:\n";
        string iname;
        cin >> iname;

        cout << "Enter output file name:\n";
        string oname;
        cin >> oname;

        vector<string> lines{ read_from_file(iname) };
        remove_punct(lines);
        write_to_file(lines, oname);

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
