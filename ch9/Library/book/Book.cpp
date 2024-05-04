#include "Book.hpp"

#include "std_lib_facilities.h"

namespace my_lib {

Book::Book(const string &i, const string &t, const string &a, Genre g, const Chrono::Date &cry)
    : m_isbn_{i}, 
      m_title_{t},
      m_author_{a},
      m_genre_{g},
      m_copyright_year_{cry},
      m_is_checked_{false} 
{
    if(!is_isbn(i)) error("Book::Book: invalid isbn entered ", i);
}

const string& Book::isbn() const
// return isbn 
{
    return m_isbn_;
}

const string& Book::title() const
// return tile 
{
    return m_title_;
}

const string& Book::author() const
// return author 
{
    return m_author_;
}

const string& Book::genre() const
// return genre 
{
    return parse_genre();
}

const Chrono::Date& Book::copyright_year() const
// return copyright year
{
    return m_copyright_year_;
}

bool Book::is_checked() const
// return true if book is checked out;
// false otherwise
{
    return m_is_checked_;
}

bool Book::is_isbn(const string &isbn) const
// true if isbn is in the format: n-n-n-x
// where n is a digit and x is either a
// digit or letter
{
    size_t n = isbn.size();
    if(n != 7) return false;

    size_t i = 0;
    for(; i != n-1; i+=2) {
        if(!isdigit(isbn[i]) || isbn[i+1] != '-') return false;
    }
    if(!isdigit(isbn[i]) && !isalpha(isbn[i])) return false;

    return true;
}

const string& Book::parse_genre() const
// return the string coresponding to Genre enum
{
    static const vector<string> genres{"Fiction", "Non-Fiction", 
                                       "Periodical", "Biography", "Children"};
    return genres.at(static_cast<size_t>(m_genre_)); // at() is just like the subscript operator
                                                     // except it can throw an exception if out-of-bounds
}

void Book::check_out() 
// set the book to checked-out
{
    m_is_checked_ = true;
}

void Book::check_in()
// set the book to checked-in
{
    m_is_checked_ = false;
}

// helper functions
bool operator==(const Book &lhs, const Book &rhs)
// returns true if the isbn matches; otherwise false
{
    return lhs.isbn() == rhs.isbn();
}

bool operator!=(const Book &lhs, const Book &rhs)
// return true if the isbn don't match; otherwise true
{
    return !(lhs == rhs);
}

ostream& operator<<(ostream &os, const Book &book)
{
    return os << "Title:\t"  << book.title()  << '\n'
              << "Author:\t" << book.author() << '\n'
              << "Genre:\t"  << book.genre()  << '\n'
              << "ISBN:\t"   << book.isbn()   << '\n';
}

} // my_lib namespace
