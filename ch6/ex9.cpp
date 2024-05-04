#include "std_lib_facilities.h"

const vector<string> place_values{"one", "ten", "hundred", "thousand"};

int get_digit(char d)
// convert character to digit
// pre-condition: d must be a digit
{
    if(!(d >= '0' && d <= '9')) error("not a digit", d);
    return d - '0';
}

int parse_input(const string &input)
// parse the input and compose them to integers
// pre-condition: the size of the input must be greater
// than zero.
{
    if(input.size() == 0) error("you did not read any digits");
    int digits = 0;
    for(size_t i = 0; i != input.size(); ++i) {
        if(input[i] != 0 || input[i] != '0') {
            digits = digits * 10 + get_digit(input[i]);
        }
    }

    return digits;
}

string read_input()
// read integers that correspond to digits
// post-condition: the size of the input is not zero
// and its size is not greater than the max number of digits
{
    string input;
    cin >> input;
    if(input.size() == 0) error("no digits read");
    if(input.size() > place_values.size()) error("Sorry, cannot handle that many digits");
    return input;
}
    
int main()
{
    try {
       
        cout << "Please enter a series of integers of no more than " << place_values.size() << " digits "
             << "(followed by \'Enter\'):\n";
        char again = ' ';
        string input;
        while(!cin.eof() && again != 'n') {
            string input = read_input();
            int digits = parse_input(input);
            cout << digits << " is ";
            for(size_t i = 0; i != input.size(); ++i) {
                cout << input[i] << ' ' << place_values[input.size() - i - 1];
                if(input[i] != '0' && input[i] != '1') {
                    cout << "s ";
                }
                else {
                    cout << ' ';
                }
            }
            cout << "\nTry again? (y/n): "; 
            cin >> again;
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
