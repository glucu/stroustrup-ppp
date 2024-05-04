#ifndef PATRON_HPP
#define PATRON_HPP

#include "std_lib_facilities.h"

namespace my_lib {

class Patron {
public:
  Patron(const string &name, unsigned lib_card);

  // non-modifying operations:
  const string& name() const;
  unsigned lib_card() const;
  double fees() const;
  bool owes_fee() const;

  // modifying operations:
  void set_fee(double fee);

private:
  string m_name_;
  unsigned m_lib_card_;
  double m_fees_;
};

// helper functions:
ostream& operator<<(ostream &os, const Patron &p);

} // my_lib namespace

#endif
