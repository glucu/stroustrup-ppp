#include "std_lib_facilities.h"

/*
 * COMMENT:
 * Again, I prefer modularity by splitting separate computations in its own functions,
 * unless the problem is trivial...very trivial. istringstream was the first thought that
 * came to mind. That is, we need to process each word in a line one by one and do the
 * comparison of the word we want to search. The ostringstream is not needed, it's more extra,
 * but I wanted to practice using the ostringstream as well.
 */

vector<string> read_from_file(const string &name)
{
    ifstream ifs{name};
    if(!ifs.is_open()) error("read_from_file: Failed to open file ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    vector<string> tmp;
    for(string line; getline(ifs, line);) {
        tmp.push_back(line);
    }

    ifs.clear();

    return tmp;
}

void write_to_file(ostringstream &oss)
{
    ofstream ofs{"bible-output.txt", ios_base::app};
    if(!ofs.is_open()) error("write_to_file: Failed to open file output.txt");

    ofs << oss.str();
}

void lines_with_word(const vector<string> &lines, const string &word)
{
    size_t line_number{1};
    for(const string &line : lines) {
        bool is_found{};
        istringstream buffer{line};
        for(string w; buffer >> w;) {
            if(w == word) is_found = true; 
        }
        if(is_found) {
            ostringstream oss;
            oss << line_number << ": "
                << line << '\n';
            write_to_file(oss);
        }
        ++line_number;
    }
}

int main()
{
    try {
       
        cout << "Enter input file name:\n";
        string iname;
        cin >> iname;

        vector<string> lines = read_from_file(iname);

        cout << "Now, what word do you want to search for?\n";
        string word;
        cin >> word;

        lines_with_word(lines, word);
        
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
