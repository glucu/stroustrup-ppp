#include "my_book.h"

namespace my_book {
    // member function definitions:

    Book::Book(const std::string &title, const std::string &author, const std::string &isbn, const Date &copyright, const Genre genre)
        :m_title{ title }, m_author{ author }, m_isbn{ isbn }, m_copyright{ copyright }, m_genre{ genre }, m_is_checked{ false }
    {

        if (!check_isbn(m_isbn)) error("Book::Book(): isbn violated");
        if (!is_date(m_copyright.year(), m_copyright.month(), m_copyright.day()))
            error("Book::Book(): date violated");
    }

    void Book::set_isbn(const std::string &isbn) {
        // checks to see if isbn follows the invariant. If valid,
        // sets member variable isbn to the parameter.

        if (!check_isbn(isbn)) return;

        m_isbn = isbn;
    }

    bool Book::check_isbn(const std::string &isbn) {
        // checks to see if isbn is in the form
        // n-n-n-x
        // pre-condition: isbn must be of size 7

        if (isbn.size() != 7) return false;

        for (size_t i{}; i < isbn.size(); ++i) {

            char ch{ isbn[i] };

            if (i != isbn.size() - 1 && i % 2 == 0) {
                if (!std::isdigit(ch)) {
                    return false;
                }
            }
            else if (i == isbn.size() - 1) {
                if (!std::isalnum(ch)) {
                    return false;
                }
            }
            else if (ch != '-') {
                return false;
            }
        }

        return true;
    }

    bool operator==(const Book &lhs, const Book &rhs) {

        return (lhs.get_isbn() == rhs.get_isbn());
    }

    bool operator!=(const Book &lhs, const Book &rhs) {

        return !(lhs == rhs);
    }

    const std::string parse_genre(const Genre genre) {
        // in order to print the actual enumerator as a string
        // to display is along with the other members, we must
        // parse genre to its according string

        switch (genre) {
        case Genre::kFiction:
            return "Fiction";
        case Genre::kNonfiction:
            return "Non-fiction";
        case Genre::kPeriodical:
            return "Periodical";
        case Genre::kBiography:
            return "Biography";
        case Genre::kChildren:
            return "Children";
        default:
            return "Unkown Genre.";
        }
    }

    std::ostream& operator<<(std::ostream &os, const Book &b) {

        os  << "Title: " << b.get_title() << '\n'
            << "Author: " << b.get_author() << '\n'
            << "Copyright date: " << b.get_copyright() << '\n'
            << "ISBN: " << b.get_isbn() << '\n'
            << "Genre: " << parse_genre(b.get_genre()) << '\n'
            << "Checked: " << std::boolalpha << b.checked_out();

        return os;
    }

    // Patron's member functions:
    Patron::Patron(const std::string &name, const std::string &card)
        : m_name{name}, m_card{card}, m_fee{0.0} { }

    void Patron::set_fee(double fee) {
        // sets the m_fee to the fee amount.
        // pre-condition: fee must not be a negative number

        if (fee < 0.0) error("Patron::set_fee(): pre-condition violated.");

        m_fee = fee;
    }

    bool operator==(const Patron &lhs, const Patron &rhs) {

        return lhs.get_card() == rhs.get_card();
    }

    bool operator!=(const Patron &lhs, const Patron &rhs) {

        return !(lhs == rhs);
    }

    std::ostream& operator<<(std::ostream &os, const Patron &p) {

        os  << "Name: " << p.get_name() << '\n'
            << "Card number: " << p.get_card() << '\n'
            << "Fee owned: " << p.get_fee() << '\n';

        return os;
    }

    // Library member functions
    void Library::add_book(const Book &book) {

        if (is_book(book)) error("Library::add_book(): book already added");

        m_book.push_back(book);
    }

    void Library::add_patron(const Patron &patron) {

        if(is_patron(patron)) error("Library::add_patron(): patron already added");

        m_patron.push_back(patron);
    }

    void Library::check_out(Book &book, Patron &patron, const Date &date) {

        if (patron.owes_fees()) error("Library::check_out(): you owe fees");

        bool book_found{};
        bool patron_found{};
        for (const auto& b : m_book) {

            if (b == book) {
                book_found = true;
                break;
            }
        }

        for (const auto &p : m_patron) {

            if (p == patron) {
                patron_found = true;
                break;
            }
        }

        if (book_found && patron_found) {

            m_transaction.push_back(Transaction{ book, patron, date });
            book.check_out();
            patron.set_fee(10.95);
        }
    }

    std::vector<std::string> Library::with_fees() const {

        std::vector<std::string> temp;
        for (const auto &p : m_patron) {
            if (p.owes_fees()) temp.push_back(p.get_name());
        }

        return temp;
    }
    
    bool Library::is_book(const Book &book) const {

        for (const auto &b : m_book) {
            if (b == book) return true;
        }

        return false;
    }

    bool Library::is_patron(const Patron &patron) const {

        for (const auto &p : m_patron) {
            if (p == patron) return true;
        }

        return false;
    }

    std::ostream& operator<<(std::ostream& os, const Library::Transaction &t) {
        
        os << t.patron.get_name() << " checked out " << t.book.get_title() << " on " << t.date << '\n';
        
        return os;
    }

}   // namespace my_book