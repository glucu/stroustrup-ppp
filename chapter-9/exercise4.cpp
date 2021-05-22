#include "../include/std_lib_facilities.h"

/* Chapter 9: exercise 4
 *
 * Look at the headache-inducing last example of §8.4. Indent it properly
 * and explain the meaning of each construct. Note that the example doesn't
 * do anything meaningful; it is pure obfuscation.
 * 
 */

/* COMMENT:
 * Wow...just trying to indent properly honestly got my brain hurting.
 * This is a struct, and structs should just contain data, and have no invariants.
 * However, this code example is obscure and meaningless. It should be disposed of.
 * Yet I decided to organize it so it can at least be representable.
 */

struct X {

    X() {}   // default constructor.

    void f(int x) {   // function f() declared inline. Probably too long and complex to inline.

        struct Y {   // nested struct. Avoid this!

            int f() { return 1; }
            int m{};
        };

        int m{x};
        Y m2;

        return f(m2.f());   // Recursive call. No base case, infinite recursive calls
                            // another problem is the return type for f() is void.
    }

    void g(int m) {

        if(m) f(m+2);   // Bad choice to use m in the condition (although it is valid). Each call leads to a recursive call. 
        else  g(m+2);
    }

    void m3() {   // Useless...can be invoked but no logical operations are even done inside the body

    }

    void main() {   // This is a mistake. I am assuming it's suppose to be the main() function where the thread of execution begins.
                    // It's problem because it also leads to an infinite recursive call.
        X a;
        a.f(2);
    }

    int m{};
};