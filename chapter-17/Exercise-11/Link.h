#ifndef CHAPTER_17_LINK_H
#define CHAPTER_17_LINK_H

#include <string>

class Link {
public:
    std::string m_value;

    Link(const std::string &v, Link *p = nullptr, Link *s = nullptr)
        : m_value{v}, m_prev{p}, m_succ{s} { }

    Link* insert(Link *n);                          // insert n before this object
    Link* add(Link *n);                             // insert n after this object
    Link* erase();                                  // remove this object from list
    Link* find(const std::string &s);               // find s in list
    const Link* find(const std::string &s) const;   // find s in const list

    Link* advance(int n) const;                     // move n positions in list

    Link* next() const { return m_succ; }
    Link* previous() const { return m_prev; }

private:
    Link *m_prev;                                   // predecessor
    Link *m_succ;                                   // successor
};

#endif //CHAPTER_17_LINK_H
