#include <iostream>
#include <string>

/* 
 * COMMENT:
 *
 * I do not see what benefit comes from making this Link class generic?
 */

class Link {
public:
    struct God {
        std::string name;
        std::string mythology;
        std::string vehicle;
        std::string weapon;
    };

public:

    Link(const God &v, Link *p = nullptr, Link *s = nullptr);

    Link* insert(Link *n);
    Link* add(Link *n);
    Link* add_ordered(Link *n);
    Link* erase();
    Link* find(const std::string &s);
    const Link* find(const std::string &s) const;

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

Link* Link::find(const std::string &s)
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

int main()
{
    Link lst{{}};
}
