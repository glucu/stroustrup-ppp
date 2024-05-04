#include "Rational.hpp"

int main()
{
    try {

        cout << "Please enter a series of rational numbers (fractions of the form: a/b) separated by a space "
             << "(followed by any non-digit chracter to quit):\n";
        Rational r1{}, r2{};
        while(cin >> r1 >> r2) {
            cout << "Fractions entered: " << r1 << " - " << r2 << "\n\n"
                 << r1 << " == " << Rational::float_conversion(r1) << '\n'
                 << r2 << " == " << Rational::float_conversion(r2) << '\n'
                 << r1 << " == " << r2 << "? " << ((r1 == r2) ? "Equal" : "Not Equal") << "\n\n"
                 << r1 << " + " << r2 << " == " << r1 + r2 << " == " << Rational::float_conversion(r1+r2) << '\n'
                 << r1 << " - " << r2 << " == " << r1 - r2 << " == " << Rational::float_conversion(r1-r2) << '\n'
                 << r1 << " * " << r2 << " == " << r1 * r2 << " == " << Rational::float_conversion(r1*r2) << '\n'
                 << r1 << " / " << r2 << " == " << r1 / r2 << " == " << Rational::float_conversion(r1/r2) << "\n\n"
                 << "> ";
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
