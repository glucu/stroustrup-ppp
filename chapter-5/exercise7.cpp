#include "../include/std_lib_facilities.h"

/*  Chapter 5: exercise 7
 *  
 *  Quadratic equations are of the form a · x2 + b · x + c = 0
 *  To solve these, one uses the quadratic formula:
 *  x = -b ± sqrt(b2 - 4ac) / 2a
 *  There is a problem though: if b2-4ac is less than zero, then it will fail.
 *  Write a program that can calculate x for a quadratic equation. Create a
 *  function that prints out the roots of a quadratic equation, given a, b, c,
 *  and have it throw an exception if b2-4ac is less than zero. Have the main
 *  function of the program call the function, and catch the exception if there
 *  is an error. When the program detects an equation with no real roots,
 *  have it print out a message. How do you know that your results are plausible? Can you check that they are correct?
 */

void print_roots(double x1, double x2) {

    std::cout << "x = " << x1 << " or " << x2 << '\n';
}

void print_root(double x) {

    std::cout << "x = " << x << '\n';
}

void quad_solver() {
    
    double a{}, b{}, c{};
    while(std::cin >> a >> b >> c) {
        if(std::cin) {
            if(a == 0) {
                error(std::string{"a can't be zero."});
            }
            else {
                double discriminant{ b*b - 4*a*c };
                double x1{};
                double x2{};

                if(discriminant > 0) {
                    // We get two Real solutions
                    x1 = (-b + std::sqrt(discriminant)) / (2*a);
                    x2 = (-b - std::sqrt(discriminant)) / (2*a);
                    print_roots(x1, x2);
                }
                else if(discriminant == 0) {
                    // We get one Real solution (both are the same)
                    x1 = (-b + std::sqrt(discriminant)) / (2*a);
                    print_root(x1);
                }
                else {
                    std::cout << "A pair of complex solutions, can't solve.\n";
                }
            }
        }
        else {
            error(std::string{"Bad input read in std::cin"});
        }
    }
}

int main() {

    try {

        std::cout << "Enter the coefficients for variables a, b, and c\n"
                  << "for the quadratic equation (ax^2 + bx + c = 0):\n\n";
        std::cout << ">> ";
        quad_solver();

        return 0;
        
    }
    catch(std::runtime_error &e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong.\n";
        return 2;
    }

}