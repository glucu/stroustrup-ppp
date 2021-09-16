#include <iostream>
#include <vector>
#include <exception>

/* Chapter 17: Part 1 Drill
 *
 * 1.  Allocate an array of ten ints on the free store using new.
 * 2.  Print the values of the ten ints to cout.
 * 3.  Deallocate the array (using delete[]).
 * 4.  Write a function print_array10(ostream& os, int* a) that prints out the 
 *     values of a (assumed to have ten elements) to os.
 * 5.  Allocate an array of ten ints on the free store; initialise it with the 
 *     values 100, 101, 102, etc.; and print out its values.
 * 6.  Allocate an array of 11 ints on the free store; initialise it with the 
 *     values 100, 101, 102, etc.; and print out its values.
 * 7.  Write a function print_array(osteam& os, int* a, int n) that prints out 
 *     the values of a (assumed to have n elements) to os.
 * 8.  Allocate an array of 20 ints on the free store; initialise it with the 
 *     values 100, 101, 102, etc.; and print out it's values.
 * 9.  Did you remember to delete the arrays? (If not, do it).
 * 10. Do 5, 6, and 8 using a vector instead of an array and a  print_vector() 
 *    instead of print_array().
 */

// Drill 4
void print_array10(std::ostream &os, const int *const a)
{
    for(int i{}; i != 10; ++i) {
            os << a[i] << ' ';
    }
        os << '\n';
}

// Drill 7
void print_array(std::ostream &os, const int *const a, int n)
{
    for(int i{}; i != n; ++i) {
        os << a[i] << ' ';
    }
    os << '\n';
}

// Drill 10
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
        int *pi1{ new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9} };

        // Drill 2
        for(int i{}; i != 10; ++i) {
            std::cout << pi1[i] << ' ';
        }
        std::cout << '\n';

        // Drill 3
        delete[] pi1;

        // Drill 5
        int *pi2{ new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109} };
        print_array10(std::cout, pi2);

        // Drill 6
        int *pi3{ new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110} };
        std::cout << pi3[0] << ' ';
        print_array10(std::cout, pi3+1);

        // Drill 8
        int *pi4{ new int[20]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                              111, 112, 113, 114, 115, 116, 117, 118, 119} };
        print_array(std::cout, pi4, 20);

        // Drill 9
        delete[] pi2;
        delete[] pi3;
        delete[] pi4;

        // Drill 10
        std::vector<int> ivec;
        for(int i{}; i != 10; ++i) {
            ivec.push_back(100+i);
        }
        print_vector(std::cout, ivec);

        ivec.clear();
        for(int i{}; i != 11; ++i) {
            ivec.push_back(100+i);
        }
        print_vector(std::cout, ivec);

        ivec.clear();
        for(int i{}; i != 20; ++i) {
            ivec.push_back(100+i);
        }
        print_vector(std::cout, ivec);

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