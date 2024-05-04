#include "Library.hpp"

namespace my_lib {

Library::Library() {} 

const vector<Book>& Library::books() const
{
  return m_books_;
}

const vector<Patron>& Library::patrons() const
{
  return m_patrons_;
}

const vector<string> Library::patron_fees() const
// return the names of Patrons who owe fees
{
  vector<string> names;
  for(const Patron &p : m_patrons_) {
    if(p.owes_fee()) names.push_back(p.name());
  }
  return names;
}

bool Library::is_book(const Book &book) const 
// check if book is already in the Library's database
{
  for(const Book &b : m_books_) {
    if(b.isbn() == book.isbn()) return true;
  }
  return false;
}

void Library::add_book(const Book &b)
// add b in the book database
// pre-condition: book must not alrady be in the database
{
  if(is_book(b)) error("add_book: book already exists in the database");
  m_books_.push_back(b);
}

bool Library::is_patron(const Patron &patron) const
// check if patron is already in the Library's database
{
  for(const Patron &p : m_patrons_) {
    if(p.lib_card() == patron.lib_card()) return true;
  }
  return false;
}

void Library::add_patron(const Patron &p)
// add p in Patron database
// pre-condition: patron must not already be in the Patron database
{
  if(is_patron(p)) error("add_patron: patron already exists in the database");
  m_patrons_.push_back(p);
}

bool Library::is_checked_out(const Book &book) const
// check if the book is already checked out
{
  return book.is_checked();
}

Book& Library::book(const Book &book)
// return the book b if it exists
{
  for(Book &b : m_books_) {
    if(b.isbn() == book.isbn()) return b;
  }
  error("book: Book does not exist in the database");
}

Patron& Library::patron(const Patron &patron)
// return the patron if it exists
{
  for(Patron &p : m_patrons_) {
    if(p.lib_card() == patron.lib_card()) return p;
  }
  error("patron: Patron does not exist in the database");
}

bool Library::owes_fee(const Patron &p) const
// check if p owes any fees
{
  return p.owes_fee();
}

void Library::check_out(const Book &b, const Patron &p, const Chrono::Date &d) 
// 
// pre-conditon: book and patron must exist and the book must not be already
// checked out and the patron does not owe any fees
{
  Book &lb = book(b);
  Patron &lp = patron(p);
  
  if(is_checked_out(b))     error("check_out: The book is currently checked-out");
  if(lp.owes_fee())         error("check_out: Sorry, you still owe a fee of ", p.fees());

  m_transactions_.push_back({b, p, d});
  lb.check_out();
  lp.set_fee(12.33);
}

ostream& operator<<(ostream &os, const Library &l)
{
  const vector<Book> vb = l.books();
  const vector<Patron> vp = l.patrons();

  os << "*****LIBRARY DATABASE*****\n\n*****BOOK LIST*****\n";
  for(size_t i = 0; i != vb.size(); ++i) {
    os << vb[i] << '\n';
  }
  os << "*****PATRON LIST*****\n";
  for(size_t i = 0; i != vp.size(); ++i) {
    os << vp[i] << '\n';
  }
  return os;
}

} // my_lib namespace
