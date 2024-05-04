#include "std_lib_facilities.h"

struct Link {
    string value;
    Link *prev;
    Link *succ;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
};


Link* insert(Link *p, Link *n)
// insert n before p; return n
{
    if(n == nullptr) return p;
    if(p == nullptr) return n;

    n->succ = p;
    if(p->prev) p->prev->succ = n;
    n->prev = p->prev;
    p->prev = n;
    return n;
}

Link* erase(Link *p)
// remove *p from list; return p's successor
{
    if(!p) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* find(Link *p, const string &s)
// find s in list; return nullptr for "not found"
{
    for(auto q = p; q; q = q->succ) {
        if(q->value == s) return q;
    }
    return nullptr;
}

Link* advance(Link *p, int n)
// move n position in list; 
// return nullptr for "not found"
{
    if(!p) return nullptr;
    if(0 < n) {
        while(n--) {
            if(!p->succ) return nullptr;
            p = p->succ;
        }
    }
    else if(n < 0) {
        while(n++) {
            if(!p->prev) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

void print_all(Link *p)
{
    cout << "{ ";
    for(auto q = p; q; q = q->succ) {
        cout << q->value;
        if(q->succ) cout << ", ";
    }
    cout << " }\n";
}

int main()
{
    try {
       
        Link *norse_gods = new Link{"Thor"};
        norse_gods = insert(norse_gods, new Link{"Odin"});
        norse_gods = insert(norse_gods, new Link{"Zeus"});
        norse_gods = insert(norse_gods, new Link{"Freia"});

        Link *greek_gods = new Link{"Hera"};
        greek_gods = insert(greek_gods, new Link{"Athena"});
        greek_gods = insert(greek_gods, new Link{"Mars"});
        greek_gods = insert(greek_gods, new Link{"Poseidon"});

        Link *p = find(greek_gods, "Mars");
        if(p) p->value = "Ares";

        p = find(norse_gods, "Zeus");
        if(p) {
            if(p == norse_gods) norse_gods = p->succ;
            erase(p);
            greek_gods = insert(greek_gods, p);
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
