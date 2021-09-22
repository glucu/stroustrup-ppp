#include "Singly_linked_list.h"

#include <stdexcept>

Link* Link::insert(Link *n)
{
    if(!n)    return this;
    if(!this) return n;

    n->m_succ = this;
    return n;
}

Link* Link::add(Link *n)
{
    if (!n)    return this;
    if (!this) return n;

    n->m_succ = m_succ;
    m_succ = n;

    return this;
}

Link* Link::erase()
{
    if(!this) return nullptr;
    Link *tmp{m_succ };
    m_succ = nullptr;
    return tmp;
}

Link* Link::find(const std::string &s)
{
    Link *curr{this };
    while(curr) {
        if(curr->value == s) return curr;
    }

    return nullptr;
}

const Link* Link::find(const std::string &s) const
{
    Link *curr{const_cast<Link*>(this) };
    while(curr) {
        if(curr->value == s) return curr;
    }

    return nullptr;
}

const Link* Link::advance(int n) const
{
    if(!this) return nullptr;
    if (n < 0) throw std::runtime_error("advance(int n): must move forward only.");
    if (0 < n) {
        if (!m_succ) return nullptr;

        return m_succ->advance(--n);
    }
    return this;
}