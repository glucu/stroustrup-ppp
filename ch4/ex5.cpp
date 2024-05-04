#include "std_lib_facilities.h"

int main()
{
    try {
       
        while(true) {
            cout << "Please enter two floating-point values followed by an operator. (\'+\', \'-\', \'*\', \'/\'):\n";
            double val1 = 0;
            double val2 = 0;
            char operation = ' ';
            cin >> val1 >> val2 >> operation;
            if(cin) {
                string op;
                double result = 0;
                switch(operation) {
                case '+':
                    result = val1 + val2;
                    op = "The sum of ";
                    break;
               case '-':
                    result = val1 - val2;
                    op = "The difference of ";
                    break;
               case '*':
                    result = val1 * val2;
                    op = "The product of ";
                    break;
               case '/':
                    if(val2 == 0) error("Divide by zero");
                    result = val1 / val2;
                    op = "The ratio of ";
                    break;
               default:
                    cout << operation << " is not an operator that I know. Try again.\n";
                    break;
                }
                if(!op.empty()) {
                    cout << op << val1 << " and " << val2 << " is " << result << '\n';
                }
            }
            else if(cin.eof()) error("EOF reached");
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid read. Please try again.\n";
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
