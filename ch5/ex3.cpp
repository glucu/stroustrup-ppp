#include "std_lib_facilities.h"

// COMMENT:
// If we are dealing with the case of absolute zero, why not deal the case of absolute hot? Now, as far as I know,
// there isn't a universally agreed-upon maximum temperature. Here I just set it to 1 trillion. ;)

constexpr double kAbsolute_zero{-273.15};
constexpr double kAbsolute_hot{1.0e12}; // 1 trillion degrees Celsius

double ctok(double c) 
{
    double k = c + 273.15;
    return k;
}

int main()
{
    try {
       
        cout << "Please enter a temperature in Celsius to convert to Kelvin temperature:\n"; 
        double c{};
        while(cin >> c) {
            if(c < kAbsolute_zero) error("That is below absolute zero! Impossible!");
            if(c > kAbsolute_hot) error("That is above absolute hot! Impossible!");
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
