#include "Link.hpp"

void print_all(Link *p)
{
    cout << "{ ";
    for(auto q = p; q; q = q->next()) {
        cout << q->value;
        if(q->next()) cout << ", ";
    }
    cout << " }\n";
}

int main()
{
    try {
       
        Link *norse_gods{new Link{"Thor"}};
        norse_gods = norse_gods->insert(new Link{"Odin"});
        norse_gods = norse_gods->insert(new Link{"Zeus"});
        norse_gods = norse_gods->insert(new Link{"Freia"});

        Link *greek_gods = new Link{"Hera"};
        greek_gods = greek_gods->insert(new Link{"Athena"});
        greek_gods = greek_gods->insert(new Link{"Mars"});
        greek_gods = greek_gods->insert(new Link{"Poseidon"});

        Link *p = greek_gods->find("Mars");
        if(p) p->value = "Ares";

        p = norse_gods->find("Zeus");
        if(p) {
            if(p == norse_gods) norse_gods = p->next();
             norse_gods->erase(p);
            greek_gods = greek_gods->insert(p);
        }

        print_all(norse_gods);
        cout << '\n';

        print_all(greek_gods);
        cout << '\n';

        return 0;
    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
