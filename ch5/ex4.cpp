#include "std_lib_facilities.h"

constexpr double kAbsolute_zero{-273.15};

double ctok(double c)
// converts Celsius to Kelvin
// pre-condition: c is not below absolute zero
{
    if(c < kAbsolute_zero) error("Temperature is less than absolute zero. Not possible");
    return c + 273.15;
}

int main()
{
    try {
       
        cout << "Please enter a temperature in Celsius and I will convert it to Kelvin temperature:\n";
        double c{};
        while(cin >> c) {
            double k = ctok(c);
            cout << c << "C == " << k << "K\n";
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
