#include <iostream>
#include <exception>

/* Chapter 17: exercise 9
 *
 * Which way does the stack grow: up (toward higher addresses) or down (towards
 * lower addresses)? Which way does the free store initially grow (that is,
 * before you use delete)? Write a program to determine the answers.
 */

int main()
{
    try {

        int val1{};
        int val2{};
        int stack_diff{ &val2 - &val1 };

        if(stack_diff > 0) {
            std::cout << "The stack grows towards higher addresses.\n";
        }
        else {
            std::cout << "The stack grows towards lower addresses.\n";
        }

        int *heap_array{ new int[5]{} };
        int heap_diff{ &heap_array[1] - &heap_array[0] };
        if(heap_diff > 0) {
            std::cout << "The free store grows towards higher addresses.\n";
        }
        else {
            std::cout << "The free store grows towards lower addresses.\n";
        }

        delete[] heap_array;

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cout << "something went wrong.\n";
    }
}
