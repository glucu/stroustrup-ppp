#ifndef MY_BOOK_H
#define MY_BOOK_H

/* COMMENT:
 * I may come back to this in the future and fix it up futher. 
 * Perhaps make it more useful. It's an exercise, so I can't spend too much
 * time on it. I did enjoy working on it though.
 */

#include "../include/std_lib_facilities.h"
#include "Chrono.h"

namespace my_book {

    using chrono::Date;

    enum class Genre {

        kFiction,
        kNonfiction,
        kPeriodical,
        kBiography,
        kChildren
    };

    // Book class declaration
    class Book {
    public:
        Book(const std::string &title, const std::string &author, const std::string &isbn, const Date &copyright, const Genre genre);
        
        // nonmodifying operations:
        const std::string& get_title()         const { return m_title; }
        const std::string& get_author()        const { return m_author; }
        const std::string& get_isbn()          const { return m_isbn; }
        const Date&        get_copyright()     const { return m_copyright; }
        const Genre        get_genre()         const { return m_genre;  }
        const bool         checked_out()       const { return m_is_checked; }

        // modifying operations:
        void set_title(const std::string &title)   { m_title = title; }
        void set_author(const std::string &author) { m_author = author; }
        void set_isbn(const std::string &isbn);
        void set_copyright(const Date &date)       { m_copyright = date; }
        void set_genre(const Genre genre)          { m_genre = genre;  }


        void check_in()  { m_is_checked = false; };
        void check_out() { m_is_checked = true; };

        friend bool operator==(const Book &lhs, const Book &rhs);
        friend bool operator!=(const Book &lhs, const Book &rhs);
        friend std::ostream& operator<<(std::ostream &os, const Book &b);

    private:
        std::string m_title;
        std::string m_author;
        std::string m_isbn;
        Date m_copyright;
        Genre m_genre;

        bool m_is_checked;      

        bool check_isbn(const std::string &isbn);   // is isbn in the form: n-n-n-x?
    };


    // Patron class declaration
    class Patron {
    public:
        Patron(const std::string &name, const std::string &card);


        // nonmodifying operations:
        const std::string& get_name()  const { return m_name; }
        const std::string& get_card()  const { return m_card;  }
        const double       get_fee()   const { return m_fee; }
        bool               owes_fees() const { return m_fee > 0.0; }

        // modifying operations:
        void set_name(const std::string &name) { m_name = name; }
        void set_card(const std::string &card) { m_card = card; }
        void set_fee(double fee);

        friend bool operator==(const Patron &lhs, const Patron &rhs);
        friend bool operator!=(const Patron &lhs, const Patron &rhs);

        friend std::ostream& operator<<(std::ostream &os, const Patron &p);

    private:
        std::string m_name;
        std::string m_card;
        double m_fee;
    };

    // Library class declaration
    class Library {
    public:
        struct Transaction {
            Book book;
            Patron patron;
            Date date;
        };

        // nonmoifying operations:
        std::vector<std::string> with_fees() const;
         

        // modifying operations:
        void add_book(const Book &book);
        void add_patron(const Patron &patron);
        void check_out(Book &b, Patron &p, const Date &d);

        friend std::ostream& operator<<(std::ostream &os, const Transaction &t);

    private:
        std::vector<Book> m_book;
        std::vector<Patron> m_patron;
        std::vector<Transaction> m_transaction;

        bool is_book(const Book &b) const;
        bool is_patron(const Patron &p) const;
    };

}   // namespace my_book

#endif   // MY_BOOK_H