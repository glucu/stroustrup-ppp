#ifndef LINK_HPP
#define LINK_HPP

#include "std_lib_facilities.h"

class Link {
public:
    struct God {
        string name;
        string mythology;
        string vehicle;
        string weapon;
    };

public:

    Link(const God &v, Link *p = nullptr, Link *s = nullptr);

    Link* insert(Link *n);
    Link* add(Link *n);
    Link* add_ordered(Link *n);
    Link* erase();
    Link* find(const string &s);
    const Link* find(const string &s) const;

    Link* advance(int n);

    void print_all() const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

public:
    God value;

private:
    Link *prev;
    Link *succ;
};

#endif
