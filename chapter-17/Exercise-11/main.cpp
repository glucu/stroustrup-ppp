#include "Link.h"

#include <iostream>
#include <exception>

/* Chapter 17: exercise 11
 *
 * Complete the "list of gods" example from section 17.10.1 and run it
 */

void print_all(Link *head)
{
    Link *curr{ head };
    std::cout << "{ ";
    while(curr) {
        std::cout << curr->m_value;
        if(curr = curr->next()) std::cout << ", ";
    }
    std::cout << " }";
}

int main()
{
    try {

        Link *norse_gods{ new Link{"Thor"} };
        norse_gods = norse_gods->insert(new Link{"Odin"});
        norse_gods = norse_gods->insert(new Link{"Zeus"});
        norse_gods = norse_gods->insert(new Link{"Freia"});

        Link *greek_gods{ new Link{"Hera"}};
        greek_gods = greek_gods->insert(new Link{"Athena"});
        greek_gods = greek_gods->insert(new Link{"Mars"});
        greek_gods = greek_gods->insert(new Link{"Posseidon"});

        Link *p{ greek_gods->find("Mars") };
        if(p) {
            p->m_value = "Ares";
        }

        Link *p2{ norse_gods->find("Zeus") };
        if(p2) {
            if(p2 == norse_gods) {
                norse_gods = p2->next();
            }
            p2->erase();
            greek_gods = greek_gods->insert(p2);
        }

        print_all(norse_gods);
        std::cout << '\n';

        print_all(greek_gods);
        std::cout << '\n';

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
