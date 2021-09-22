#include "Singly_linked_list.h"

#include <iostream>
#include <exception>

/* Chapter 17: exercise 14
 *
 * Could the "list of gods" example from Section 17.10.1 have been written using
 * a singly-linked list; that is,could we have left the prev member out of Link?
 * Why might we want to do that? For what kind of examples would it make sense to
 * use a singly-linked list? Re-implement that example using only a singly-linked
 * list.
 */

void print_all(Link *unis)
{
    Link *curr{ unis };
    while(curr) {
        std::cout << curr->value << '\n';
        curr = curr->next();
    }
}

int main()
{
    try {

        Link *unis{ new Link{"University of Illinois Springfield"} };
        unis = unis->add(new Link{"Harvard University"});
        unis = unis->add(new Link{"Massachusetts Institute of Technology"});
        unis = unis->add(new Link{"Stanford University"});
        unis = unis->add(new Link{"UC Berkeley "});

        print_all(unis);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "something went wromg.\n";
        return 2;
    }
}