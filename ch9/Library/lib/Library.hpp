#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include "Chrono.hpp"
#include "Patron.hpp"

#include "std_lib_facilities.h"

namespace my_lib {

class Library {
public:
  struct Transactions {
    Book book;
    Patron patron;
    Chrono::Date date;
  };

public:
  Library(); // default constructor

  // non-modifying operations:
  const vector<Book>& books() const;
  const vector<Patron>& patrons() const;
  const vector<string> patron_fees() const;

  // modifying operations:
  void add_book(const Book &b);
  void add_patron(const Patron &p);
  void check_out(const Book &b, const Patron &p, const Chrono::Date &d);
  Book& book(const Book &b);
  Patron& patron(const Patron &p);

private:
  bool is_book(const Book &b) const; 
  bool is_patron(const Patron &p) const;
  bool is_checked_out(const Book &b) const;
  bool owes_fee(const Patron &p) const;

private:
  vector<Book> m_books_;
  vector<Patron> m_patrons_;
  vector<Transactions> m_transactions_;
};

// helper functions:
ostream& operator<<(ostream &os, const Library &l);

} // my_lib namespace

#endif
