#ifndef BOOK_HPP
#define BOOK_HPP

#include "Chrono.hpp"

#include "std_lib_facilities.h"

namespace my_lib {

class Book
{
public:
    enum class Genre {
        kFiction,
        kNonFiction,
        kPeriodical,
        kBiography,
        kChildren
    };

public:
    Book(const string &i, const string &t, const string &a, Genre g, const Chrono::Date &cry); 

    // non-modifying operations:
    const string& isbn() const;
    const string& title() const;
    const string& author() const;
    const string& genre() const;
    const Chrono::Date& copyright_year() const;
    bool is_checked() const;
    
    // modifying operations:
    void check_out();
    void check_in();

private:
    bool is_isbn(const string &isbn) const; 
    const string& parse_genre() const;
        
private:
    string m_isbn_;
    string m_title_;
    string m_author_;
    Genre m_genre_;
    Chrono::Date m_copyright_year_;
    bool m_is_checked_;
};

// helper functions
bool operator==(const Book &lhs, const Book &rhs);
bool operator!=(const Book &lhs, const Book &rhs);
ostream& operator<<(ostream &os, const Book &book);

} // my_lib namespace

#endif
