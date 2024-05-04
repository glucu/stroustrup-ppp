#include "vector.hpp"

#include <iostream>
#include <stdexcept>

/*
 * error: lvalue required as left operand of assignment
 */

int main()
{
    try {

        vector v(10);
        double x = v[2];
        std::cout << "x == " << x << '\n';
        v[3] = x; // requires lvalue but operator[] returns a rvalue
        
        return 0;
    }
    catch(std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
