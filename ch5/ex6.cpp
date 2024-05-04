#include "std_lib_facilities.h"

constexpr double kAbsolute_zero_cel{-273.15};
constexpr double kAbsolute_zero_fah{-459.67};
const string kQuit{"q"};

double ctof(double c)
// convert Celsius to Fahrenheit
// pre-condition: Celsius not below absolute zero
{
    if(c < kAbsolute_zero_cel) error("temperature is below absolute zero!");
    return c*9.0/5+32;
}

double ftoc(double f)
// convert Fahrenheit to Celsius
// pre-condition: Fahrenheit not below absolute zero
{
    if(f < kAbsolute_zero_fah) error("temperature is below absolute zero!");
    return (f-32.0)*5/9;
}

int main()
{
    try {
       
        cout << "Please enter a temperature in either Celsius or Fahrenheit followed by a unit to convert (C,c,F,f):\n";
        string again;
        while(again != kQuit) {
            double temp{};
            char unit{};
            if(cin >> temp) {
                cin >> unit;
                switch(unit) {
                case 'C':
                case 'c':
                    cout << temp << "C == " << ctof(temp) << "F.\n";
                    break;
                case 'F':
                case 'f':
                    cout << temp << "F == " << ftoc(temp) << "C.\n";
                    break;
                default:
                    cout << unit << " is not known. Valid values are C, c, F, or f.\n";
                    break;
                }

                cout << "Try again? (Enter \'q\' to quit):\n";
                cin >> again;
            }
            else {
                if(cin.eof()) error("EOF reached");
                cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You did not read a numeric number. Try again.\n";
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
