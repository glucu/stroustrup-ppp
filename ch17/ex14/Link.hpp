#ifndef LINK_HPP
#define LINK_HPP

#include "std_lib_facilities.h"

class Link {
public:
	string value;

	Link(const string &v, Link *s = nullptr);

	Link* insert(Link *n);
	Link* add(Link *n);
	Link* erase(Link *n);
	Link* find(const string &v);
	const Link* find(const string &v) const;

	Link* advance(int n) const;

	Link* next() { return succ; }

private:
	Link *succ;
};

#endif
