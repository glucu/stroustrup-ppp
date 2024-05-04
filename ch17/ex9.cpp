#include <iostream>
#include <stdexcept>

/*
 * COMMENT:
 * This is not an easy exercise per-say because the growth of the stack (for example)
 * is dependent on the architecture, OS, or compiler settings. Orginally, I wrote a recursive 
 * function to dtermine the stack growth, but realize that the compilier may perform "tail call optimization (TCO)".
 * TCO, where you are able to avoid allocating a new stack frame for a function because the calling function will 
 * simply return the value that it gets from the called function.
 *
 * I am no expert, but I think it is as simple (maybe?). allocating a C-style array ensures allocation on the stack,
 * especially if the size is big enough (to be safe, 100 ints for example). You can't store an array in registers and an array in C must 
 * be allocated sequentially in a continuous chunk of memory otherwise pointer arithmetic doesn't work.
 *
 */

int main()
{
    try {
        
        bool is_up{};
        int ai[100];
        for(int i{1}; i != 100; ++i) {
            if(&ai[i] > &ai[i-1]) is_up = true;
            else                  is_up = false;
        }
        if(is_up) std::cout << "Stack grows up.\n";
        else      std::cout << "Stack grows down.\n";


        double *ad = new double[100];
        for(int i{1}; i != 100; ++i) {
            if(&ad[i] > &ad[i-1]) is_up = true;
            else                  is_up = false;
        }

        if(is_up) std::cout << "Heap grows up.\n";
        else      std::cout << "Heap grows down.\n";

        delete[] ad;

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
