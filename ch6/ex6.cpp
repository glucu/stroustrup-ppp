#include "std_lib_facilities.h"

/*
      English Grammar:

      Sentence:
        Noun Verb
        Article Noun Verb
        Sentence Conjunction Sentence
      Article:
        "The"
      Conjunction:
        "and"
        "or"
        "but"
      Noun:
        "birds"
        "fish"
        "C++"
     Verb:
        "rules"
        "fly"
        "swim"

    COMMENT:
    Surprisingly, this was not too difficult if you follow the similar structure that was used for the calculator program. Do recall that in chapter 3.6.1, Stroustrup does
    state, "Note how similar this program is to the one from 3.5.1. Obviously, we just took the program from 3.5.1 and modified it a bit to serve our new purpose. That is a very common technique....". That is what I did. The program is plausible enough, although it can be further improved.

 */


const vector<string> conjs{"and", "or", "but"};
const vector<string> nouns{"birds", "fish", "C++"};
const vector<string> verbs{"rules", "fly", "swim"};
const vector<string> articles{"the"};

class Token_stream
{
public:
    Token_stream()
        : full{},
          buffer{} {}

    string get();
    void putback(const string &word);

private:
    bool full;
    string buffer;
};

string Token_stream::get()
{
    if(full) {
        full = false;
        return buffer;
    }

    string word;
    cin >> word;
    if(cin.eof()) error("End of File reached");
    return word;
}

void Token_stream::putback(const string &word)
{
    if(full) error("putback: buffer is full");

    buffer = word;
    full = true;
}

Token_stream ts;


bool conjunction()
{
    string word = ts.get();
    for(size_t i = 0; i != conjs.size(); ++i) {
        if(word == conjs[i]) {
            return true;
        }
    }
    return false;
}
            

bool verb()
{
    string word = ts.get();
    for(size_t i = 0; i != verbs.size(); ++i) {
        if(word == verbs[i]) {
            return true;
        }
    }
    return false;
}

bool article()
{
    string word = ts.get();
    for(size_t i = 0; i != articles.size(); ++i) {
        if(word == articles[i]) {
            return true;
        }
    }
    ts.putback(word);
    return false;
}

bool noun()
{
    article(); 
    string word = ts.get();
    for(size_t i = 0; i != nouns.size(); ++i) {
        if(word == nouns[i]) {
            return verb();
        }
    }
    return false;
}


bool sentence()
{
    if(!noun()) return false;

    string word = ts.get();
    if(word == "." || word == "!") return true;
    ts.putback(word);
    if(!conjunction()) return false;

    return sentence();
}

int main()
{
    try {
        

        cout << "Enter a sentence of the simplified grammar (terminated by a \'.\' or a \'!\'):\n";
        string quit{};
        while(quit != "quit") {
            cout << "> ";
            if(sentence()) {
                cout << "Ok!\n";
            }
            else {
                cout << "Not Ok!\n";
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter another sentence? (Enter \'quit\' to stop): ";
            cin >> quit;
            if(cin.eof()) error("End of File reached");
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
