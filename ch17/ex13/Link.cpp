#include "Link.hpp"

#include "std_lib_facilities.h"

Link::Link(const God &v, Link *p, Link *s)
    : value{v}, prev{p}, succ{s} { }

Link* Link::insert(Link *n)
// insert n before this; return n
{
    if(!n) return this;
    if(!this) return n;

    n->succ = this;
    if(prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link *n)
// insert n after this; return n
{
    if(!n) return this;
    if(!this) return n;

    n->prev = this;
    if(succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link* Link::add_ordered(Link *n)
{
    if(!n)    return this;
    if(!this) return n;

    if(n->value.name < value.name) {
        return insert(n);
    }
    else {
        for(Link *curr = this; curr; curr = curr->next()) {
            if(!curr->next() || n->value.name < curr->next()->value.name) {
                curr->add(n);   
                return this;
            }
        }
    }
    return this;
}

Link* Link::erase()
// remove this from list; return this successor
{
    if(!this) return nullptr;
    if(succ) {
        if(prev) succ->prev = prev;
        else     succ->prev = nullptr;
    }
    if(prev) {
        if(succ) prev->succ = succ;
        else     prev->succ = nullptr;
    }
    return succ;
}

Link* Link::find(const string &s)
// find s in list; return nullptr for "not found"
{
    for(auto q = this; q; q = q->succ) {
        if(q->value.name == s) return q;
    }
    return nullptr;
}

Link* Link::advance(int n)
// move n position in list; 
// return nullptr for "not found"
{
    Link *p = this;
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

void Link::print_all() const
{
    for(auto curr = this; curr; curr = curr->next()) {
        cout << "God{\"" << curr->value.name << "\""
             << ", \"" << curr->value.mythology << "\""
             << ", \"" << curr->value.vehicle << "\""
             << ", \"" << curr->value.weapon << "\"}\n";
    }
}
    
              


