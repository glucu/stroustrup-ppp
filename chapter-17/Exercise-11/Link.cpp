#include "Link.h"

#include <iostream>

Link* Link::insert(Link *n)
{
    if(n == nullptr)    return this;
    if(this == nullptr) return n;

    n->m_succ = this;
    if(m_prev) m_prev->m_succ = n;
    n->m_prev = m_prev;
    m_prev = n;
    return n;
}

Link* Link::add(Link *n)
{
    if(n == nullptr)    return this;
    if(this == nullptr) return n;

    n->m_prev = this;
    if(m_succ) m_succ->m_prev = n;
    n->m_succ = m_succ;
    m_succ = n;
    return n;
}

Link* Link::erase()
{
    if(this == nullptr) return nullptr;
    if(m_succ) m_succ->m_prev = m_prev;
    if(m_prev) m_prev->m_succ = m_succ;
    return m_succ;
}

Link* Link::find(const std::string &s)
{
    Link* curr{ this };
    while(curr) {
        if(curr->m_value == s) return curr;
        curr = curr->m_succ;
    }

    return nullptr;
}

const Link* Link::find(const std::string &s) const
{
    Link* curr{ const_cast<Link*>(this) };
    while(curr) {
        if(curr->m_value == s) return curr;
        curr = curr->m_succ;
    }

    return nullptr;
}

Link* Link::advance(int n) const
{
    Link* curr{ const_cast<Link*>(this) };
    if(curr == nullptr) return nullptr;

    if(0 < n) {
        while(n--) {
            if(curr == nullptr) return nullptr;
            curr = curr->m_succ;
        }
    }
    else if(n < 0) {
        while(n++) {
            if(curr->m_prev == nullptr) return nullptr;
            curr = curr->m_prev;
        }
    }

    return curr;
}
