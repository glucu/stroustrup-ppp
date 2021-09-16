#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

/* Chapter 17 - Part 2 Drill
 *
 *	1.  Allocate an int, intialise it to 7, and assign its address to a variable p1.
 *	2.  Print out the value of p1 and of the int it points to.
 *	3.  Allocate an array of seven ints ; initialise it to 1, 2, 3, 4, 8, etc.; and 
 *	    assign its address to a variable p2.
 *	4.  Print out the value of p2 and of the array it points to.
 *	5.  Declare an int* called p3 and initialise it with p2.
 *	6.  Assign p1 to p2.
 *	7.  Assign p3 to p2.
 *	8.  Print out the values of p1 and p2 and of what they point to.
 *	9.  Deallocate all the memory you allocated from the free store.
 *	10. Allocate an array of ten ints; intialise it to 1, 2, 4, 8, etc.; and assign 
		its address to a variable p1.
 *	11. Allocate an array of ten ints, and assign its address to a variable p2.
 *	12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
 *	13. Repeat 10-12 using a vector rather than an array.
 */

void print_array(std::ostream &os, const int *const a, int n)
{
    for(int i{}; i != n; ++i) {
        os << a[i] << ' ';
    }
    os << '\n';
}

void print_vector(std::ostream &os, const std::vector<int> &ivec) 
{
    for(const auto &i : ivec) {
        os << i << ' ';
    } 
    os << '\n';
}

int main() 
{
    try {
        
        // Drill 1
        int *p1{ new int{7} };
        // Drill 2
        std::cout << "p1 == " << p1 << "; contents of p1 == " << *p1 << '\n';

        // Drill 3
        int *p2{ new int[7] };
        for(int i{}; i != 7; ++i) {
            p2[i] = std::pow(2,i);
        }
        // Drill 4
        print_array(std::cout, p2, 7);

        // Drill 5
        int *p3{ p2 };

        // Drill 6
        p2 = p1;

        // Drill 7
        p2 = p3;

        // Drill 8
        std::cout << "p1 == " << p1 << "; contents of p1 == " << *p1 << '\n';
        std::cout << "p2 == " << p2 << "; contents of p2 == " << *p2 << '\n';

        // Drill 9
        delete p1;
        delete[] p2;
        p3 = nullptr;

        // Drill 10
        p1 = new int[10];
        for(int i{}; i != 10; ++i) {
            p1[i] = std::pow(2,i);
        }

        // Drill 11
        p2 = new int[10]{};
        for(int i{}; i != 10; ++i) {
            p2[i] = p1[i];
        }

        delete[] p1;
        delete[] p2;

        // Drill 13
        std::vector<int> ivec1;
        for(int i{}; i != 10; ++i) {
            ivec1.push_back(std::pow(2, i));
        }
        print_vector(std::cout, ivec1);

        std::vector<int> ivec2{ ivec1 };
        print_vector(std::cout, ivec2);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "something went wrong.\n";
        return 2;
    }
}