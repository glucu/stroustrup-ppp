#include "std_lib_facilities.h"


void print_roots(double x1, double x2) 
{
    if(x1) cout << "x1 = " << x1 << ' ';
    if(x2) cout << "x2 = " << x2;
}

int main()
{
    try {
       
        cout << "Please enter coefficients for the ax^2+bx+c=0 equation and quadratic equation\n"
             << "will output the solutions (if they are not imaginary):\n"
             << "> ";
        double a{}, b{}, c{};
        while(cin >> a >> b >> c) {
            if(a == 0) error("not a quadratic equation. a", a);

            double discriminant = sqrt(b*b - 4 * a * c);

            double x1 = 0;
            double x2 = 0;
            if(discriminant > 0) {
                x1 = (-b + discriminant) / (2 * a);
                x2 = (-b - discriminant) / (2 * a);
            }
            else if(discriminant == 0) {
                x1 = -b / (2 * a);
            }
            else {
                cout << "There are no real roots.\n";
            }
             
            print_roots(x1, x2);

            cout << "\n> ";
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
