#ifndef LINK_HPP
#define LINK_HPP

#include "std_lib_facilities.h"

class Link {
public:
    string value;

    Link(const string &v, Link *p = nullptr, Link *s = nullptr);

    Link* insert(Link *n);
    Link* add(Link *n);
    Link* erase(Link*p);
    Link* find(const string &s);
    const Link* find(const string &s) const;

    Link* advance(int n);

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link *prev;
    Link *succ;
};

#endif
