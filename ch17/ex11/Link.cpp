#include "Link.hpp"

#include "std_lib_facilities.h"

Link::Link(const string &v, Link *p, Link *s)
    : value{v}, prev{p}, succ{s} { }

Link* Link::insert(Link *n)
// insert n before this; return n
{
    if(n == nullptr) return this;
    if(this == nullptr) return n;

    n->succ = this;
    if(prev) prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link* Link::add(Link *n)
// insert n after this; return n
{
    if(n == nullptr) return this;
    if(this == nullptr) return n;

    n->prev = this;
    if(succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link* Link::erase(Link *p)
// remove this from list; return this successor
{
    if(!p) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}

Link* Link::find(const string &s)
// find s in list; return nullptr for "not found"
{
    for(auto q = this; q; q = q->succ) {
        if(q->value == s) return q;
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
