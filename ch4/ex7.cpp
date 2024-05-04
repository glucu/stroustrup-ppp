#include "std_lib_facilities.h"

// COMMENT:
// My mind is gobbled up with the attitude of: "I'm smarter than any program! I'll break that %$@#! code!"
// This left me to test for every possible invalid input in ways a user might enter into the program, that way
// it does not misbehave. However, it left with more code to write, making it less readable to me, but at the
// expense of the program being correct (or mostly).


const vector<string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const int kBad_result{-99};

int get_digit()
{
    string digit;
    cin >> digit;
    for(int i = 0; i != int(digits.size()); ++i) {
        if(digit == digits[i]) {
            return i;
        }
    }
    return kBad_result;
}


int get_user_input()
{
    while(true) {
        int digit = 0;
        cin >> digit;
        if(cin) {
            if(digit < 0 || size_t(digit) >= digits.size()) {
                cout << "Operand " << digit << " is not a single digit number.\n"; 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                return digit;
            }
        }
        else {
            if(cin.eof()) error("EOF reached");
            cin.clear();
            digit = get_digit();
            if(digit == kBad_result) {
                cout << "Sorry, that's not a spelled-out single digit. Try again.\n";
            }
            else {
                return digit;
            }
        }
    }
}

int main()
{
    try {
       
        cout << "Welcome to the single-digit calculator.\n"
             << "Please enter a single-digit number as either a digit or a spelled out\n"
             << "Supported operators are: \'+\', \'-\', \'*\', \'/\'.\n";
        char quit{};
        while(quit != 'n') {
            cout << "> ";
            int op1 = 0;
            int op2 = 0;
            char operation = ' ';
            op1 = get_user_input();
            cin >> operation;
            if(cin.eof()) error("EOF reached");
            op2 = get_user_input();
            string op;
            int result = 0;
            switch(operation) {
            case '+':
                op = "The sum of ";
                result = op1 + op2;
                break;
            case '-':
                op = "The difference of ";
                result = op1 - op2;
                break;
            case '*':
                op = "The product of ";
                result = op1 * op2;
                break;
            case '/':
                if(op2 == 0) error("Divide by zero");
                op = "The ratio of ";
                result = op1 / op2;
                break;
            case '%':
                if(op2 == 0) error("Divide by zero");
                op = "The remainder of ";
                result = op1 % op2;
                break;
            default:
               error("bad operator read"); 
            }
            
            cout << op << op1 << " and " << op2 << " is " << result << '\n';

            cout << "Try again? (y/n):\n";
            cin >> quit;
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
