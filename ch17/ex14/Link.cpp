#include "Link.hpp"

Link::Link(const string &v, Link *s)
	: value{v}, succ{s} {}

Link* Link::insert(Link *n)
// insert n before this; return n
{
	if(!n)    return this;
	if(!this) return n;

	n->succ = this;
	return n;
}

Link* Link::add(Link *n)
// add after this; return this
{
	if(!n)    return this;
	if(!this) return n;

	n->succ = succ;
	succ = n;
	return this;
}

Link* Link::erase(Link *n)
// remove this object from list
{
	if(!this) return nullptr;
	// Freia -> Zeus -> Odin -> Thor -> null

	for(Link *curr = this, *prev = nullptr; curr; prev = curr, curr = curr->next()) {
		if(curr->value == n->value) {
			if(prev) {
				prev->succ = curr->succ;
			}
			else {
				Link *p = succ;
				delete curr;
				return p;
			}
			delete curr;
			return this;
		}
	}

	return nullptr;
}

Link* Link::find(const string &v)
// find v in list
{
	for(Link *curr = this; curr; curr = curr->next()) {
		if(curr->value == v) return curr;
	}

	return nullptr;
}

const Link* Link::find(const string &v) const
// find v in const list
{
	if(value == v) return this;
	else if(succ) {
		return succ->find(v);
	}
	return nullptr;
}

Link* Link::advance(int n) const
// move n positions in list
{
	if(!this) return nullptr;

	if(0 < n) {
		if(!succ) return nullptr;
		else              return succ->advance(--n);
	}

	return nullptr;
}


