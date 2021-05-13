#include "../../include/std_lib_facilities.h"

/* Chapter 8: Drill 3
 * 
 * Write a program using a single ftle containing three namespaces X, Y, and
 * Z so that the following main() works correctly:
    int main()
    {
        X::var = 7;
        X::print(); // print X's va r
        using namespace Y;
        var = 9;
        print(); // print Y's var
        { 
            using Z::var;
            using Z::print;
            var = 11;
            print(); // print Z's var
        }
        print();    // print Y's var
        X::print(); // print X's var

 * Each namespace needs to define a variable called var and a function
 * called print() that outputs the appropriate var using cout.
 */

/* COMMENT:
 * According to "Google C++ Style Guide," https://google.github.io/styleguide/cppguide.html#Namespaces
 * namespace names are all lower-case, with word seperated by underscores. So, I will abide by that.
 * Including a comment of where the namespace ends is also useful.
 */

namespace x {
    int var{};
    void print() {
        std::cout << "x::var = " << var << '\n';
    }

} // namespace x

namespace z {
    int var{};
    void print() {
        std::cout << "z::var = " << var << '\n';
    }

} // namespace z

namespace y {
    int var{};
    void print() {
        std::cout << "y::var = " << var << '\n';
    }

} // namespace y

int main() {

    x::var = 7;
    x::print();             // print x's var
    using namespace y;      // Don't! This pollutes the namespace, but I am going base on the
                            // exercise, but do be aware!
    var = 9;                // Y::var
    print();                // print Y's var
    {
        using z::var;
        using z::print;
        var = 11;
        print();            // print z's var
    }

    print();                // Print y's var
    x::print();             // print x's var

    return 0;
}