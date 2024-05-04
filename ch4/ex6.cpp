#include "std_lib_facilities.h"

int main()
{
    try {
       
        const vector<string> spelled_out_words{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        while(cin) {
            cout << "Please enter a digit between 0-9 and I will convert it to its spelled-out word:\n";
            int digit = 0;
            cin >> digit;
            if(cin && digit >= 0 && digit <= 9) {
                cout << digit << " == " << spelled_out_words[digit] << '\n';
            }
            else if(!cin) {
                if(cin.eof()) error("EOF reached");
                cin.clear();
                string digit_word;
                cin >> digit_word;
                for(size_t i = 0; i != spelled_out_words.size(); ++i) {
                    if(spelled_out_words[i] == digit_word) {
                        cout << digit_word << " == " << i << '\n';
                    }
                }
            }
            else {
                cout << "Oops: Not between 0-9.\n";
            }
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
