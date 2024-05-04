#include "std_lib_facilities.h"

// COMMENT
// I have spent too much time on this exercise. It has taught me one thing: To really understand a problem,
// write code that a computer can solve. Do you really think you understand how to solve quadratic equations? Test your knowledge 
// by having a computer solve it for you. You will realize the amount of edge cases and "bad input" you have to consider. Being precise
// and systematic is important when writing code for a computer to not only understand, but to get it right.
//
// Because of the limited precision that floating-point values can store, the answers may not be exact but "close enough". This is because
// of the hardware and the fact you can only store finite significant digits in a computer. Floating-point math is hard.


constexpr double kEpsilon{1.0e-7};

double check(double a, double b, double c, double x)
{
   double res = a*x*x+b*x+c;
   if(fabs(res) < kEpsilon) return x;
   if(0 < res && res < kEpsilon)
       cout << "poor root, off by " << res << '\n';
   else if(res < -kEpsilon) {
       cout << "poor root, off by " << res << '\n';
   }
   return x;
}

void solve_equation()
{
    double a = 0;
    double b = 0;
    double c = 0;
    cin >> a >> b >> c;
    if(cin) {
        if(a == 0) {
            if(b == 0) {
                cout << "No real roots\n";
            }
            else {
                cout << "x = " << check(a,b,c,-c/b) << '\n';
            }
        }
        else if(b == 0) {
            double discriminant = -4*a*c;
            if(discriminant == 0) {
                cout << "x = 0\n";
            }
            else if(discriminant < 0) {
                cout << "No real roots\n";
            }
            else {
                cout << "x1 == " << check(a,b,c,sqrt(discriminant) / (2*a)) << " x2 == " << check(a,b,c,-sqrt(discriminant) / (2*a)) << '\n';
            }
        }
        else {
            double discriminant = b*b - 4 * a * c;
            if(discriminant == 0) {
                cout << "x = " << check(a,b,c,-b/(2*a)) << '\n';
            }
            else if(discriminant < 0) {
                cout << "No real roots\n";
            }
            else {
                cout << "x1 == " << check(a,b,c,(-b + sqrt(discriminant)) / (2*a)) << " x2 == " << check(a,b,c,(-b - sqrt(discriminant)) / (2*a)) << '\n';
            }
        }
    }
    else {
        if(cin.eof()) error("EOF reached");
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "You did not read a floating-point number.\n\n";
    }
}


int main()
{
    try {
       
        string again;
        while(again != "no") {
            cout << "Please enter three floating-point numbers (a,b,c) to be used as coefficients in the"
                 << " quadratic equation ax^2+bx+c=0\n> ";
            solve_equation();
            cout << "Try again? (yes/no): ";
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
