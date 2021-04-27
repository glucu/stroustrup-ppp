#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter the coefficients for a, b, and c " 
              << "for the quadratic equation (ax^2 + bx + c = 0):\n";
    double a{}, b{}, c{};
    std::cin >> a >> b >> c;

    if(a == 0) {
        error("a can't be zero! Not a quadratic equation!");
    }
    else {

        double discriminant{ b*b - 4*a*c };
        double x1{};
        double x2{};

        if(discriminant > 0) {
            x1 = (-b + std::sqrt(discriminant)) / (2*a);
            x2 = (-b - std::sqrt(discriminant)) / (2*a);
            std::cout << "x = " << x1 << " or x = " << x2 << '\n';
        }
        else if(discriminant == 0) {
            x1 = -b / 2*a;
            std::cout << "x = " << x1 << '\n';
        }
        else {
            std::cout << "Sorry, no real roots, but pair of Complext solutions.\n";
        }
    }
}