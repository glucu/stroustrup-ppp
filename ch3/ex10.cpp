#include "std_lib_facilities.h"

int main()
{
    try {
        cout << "Please enter two operands followed by an operator. Supported operators: (\'+\', \'-\', \'*\', \'/\'). "
             << "Enter \'Quit\' to exit the program:\n";
        string operation;
        double op1 = 0;
        double op2 = 0;
        while(cin >> op1 >> operation >> op2 && operation != "Quit") {
            if(!cin) error("something went wrong with the read");
            string op;
            double result = 0;
            if(operation == "+") {
                op = "plus";
                result = op1 + op2;
            }
            else if(operation == "-") {
                op = "minus";
                result = op1 - op2;
            }
            else if(operation == "*") {
                op = "times";
                result = op1 * op2;
            }
            else if(operation == "/") {
                if(op2 == 0) error("divide by zero");
                op = "divided by";
                result = op1 / op2;
            }
            else {
                cout << "Sorry, " << operation << " is not an operator that is supported. Try again.\n";
            }
            
            if(!op.empty()) {
                cout << op1 << ' ' << op << ' ' << op2 << " == " << result << '\n';
            }
            cout << "Please try again: ";  
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
