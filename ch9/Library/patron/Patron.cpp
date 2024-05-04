#include "Patron.hpp"

namespace my_lib {
Patron::Patron(const string &name, unsigned lib_card)
  : m_name_{name},
    m_lib_card_{lib_card},
    m_fees_{0.0} { }

const string& Patron::name() const
// return name of patron
{
  return m_name_;
}

unsigned Patron::lib_card() const
// return library card number of Patron
{
  return m_lib_card_;
}

double Patron::fees() const
// return the fees a Patron might owe
{
  return m_fees_;
}

void Patron::set_fee(double fee) 
// set a new fee for the Patron
// pre-condition: fee must be non-negative
{
  if(fee < 0) error("set_fees: a fee must be a non-negative fee");
  m_fees_ = fee;
}

bool Patron::owes_fee() const
// return true if Patron owes a fee; otherwise
// return false
{
  return fees() > 0;
}

ostream& operator<<(ostream &os, const Patron &p)
{
  return os << "Name:\t" << p.name() << '\n'
            << "Library Card:\t" << p.lib_card() << '\n'
            << "Fees: \t$" << p.fees() << '\n';
}

} // my_lib namespace
