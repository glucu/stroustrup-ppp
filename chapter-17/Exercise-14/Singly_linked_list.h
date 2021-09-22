#ifndef CHAPTER_17_SINGLY_LINKED_LIST_H
#define CHAPTER_17_SINGLY_LINKED_LIST_H

#include <string>

class Link {
public:
    std::string value;

    Link(const std::string &v, Link *s = nullptr)
        : value{v}, m_succ{s} { }

    Link* insert(Link *n);                          // insert n before this object
    Link* add(Link *n);                             // insert n after this object
    Link* erase();                                  // remove this object from list
    Link* find(const std::string &s);               // find s in list
    const Link* find(const std::string &s) const;   // find s in const list

    const Link* advance(int n) const;                     // move n positions in list

    Link* next() const { return m_succ; }

private:
    Link *m_succ;                                   // successor
};

#endif //CHAPTER_17_SINGLY_LINKED_LIST_H
