#include "std_lib_facilities.h"

constexpr double kAbsolute_zero{-273.15};
const string kQuit{"q"};

double ctok(double c)
// converts Celsius to Kelvin
// pre-condition: c must not be below absolute zero
{
    if(c < kAbsolute_zero) error("temperature is below absolute zero!");
    return c + 273.15;
}

double ktoc(double k) 
// converts Kelvin to Celsius
// pre-condition: k must not be below absolute zero
{
    if(k < 0) error("temperature is below absolute zero!");
    return k - 273.15;
}

int main()
{
    try {
       
        string again;
        cout << "Program to convert Celsius to Kelvin or Kelvin to Celsius.\n";
        while(again != kQuit) {
            cout << "Please enter a temperature followed by a unit (\'c\' for Celsius or \'k\' for Kelvin):\n";
            double temp{};
            double result{};
            if(cin >> temp) {
                char unit{};
                cin >> unit;
                switch(unit) {
                case 'c':
                case 'C':
                   result = ctok(temp);
                   cout << temp << "C == " << result << "K.\n";
                   break;
                case 'k':
                case 'K':
                   result = ktoc(temp);
                   cout << temp << "K == " << result << "C.\n";
                   break;
                default:
                   cout << unit << " must be either \'c\' or \'k\'. Try again.\n";
                   break;
                }

                cout << "Try again? (Enter \'q\' to quit) ";
                cin >> again;
            }
            else if(cin.eof()) error("EOF reached");
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Failed to read a numeric number. Try again.\n";
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
