#include "Library.hpp"

using my_lib::Library;
using my_lib::Book;
using Chrono::Date;
using my_lib::Patron;

void add_book(Library &lib, const Book &b)
{
    try {

        lib.add_book(b);
    }
    catch(const runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return;
    }
}

void add_patron(Library &lib, const Patron &p)
{
    try {

        lib.add_patron(p);
    }
    catch(const runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return;
    }
}

void check_out(Library &lib, const Book &b, const Patron &p, const Date &d)
{
    try {

        lib.check_out(b, p, d);
    }
    catch(const runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return;
    }
}

void initialize_books(Library &lib)
{
    add_book(lib, Book("1-2-2-J", "Jurassic Park", "Micheal Crichton", Book::Genre::kNonFiction, Date(1990, Date::nov, 20)));
    add_book(lib, Book("1-2-3-J", "Jurassic Park Lost World", "Micheal Crichton", Book::Genre::kNonFiction, Date(1995, Date::sep, 8)));
    add_book(lib, Book("4-5-6-T", "The Time Traveler's Wife", "Audrey Niffenegger", Book::Genre::kFiction, Date(2003, Date::nov, 17)));
    add_book(lib, Book("4-5-6-C", "Catcher in the Rye", "J.D. Salinger", Book::Genre::kFiction, Date(1951, Date::jul, 16)));
    add_book(lib, Book("7-8-9-T", "To Kill a Mockingbird", "Harper Lee", Book::Genre::kFiction, Date(1960, Date::jul, 11)));
    add_book(lib, Book("1-2-3-H", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", Book::Genre::kFiction, Date(1997, Date::jun, 26)));
    add_book(lib, Book("4-5-6-G", "Great Expectations", "Charles Dickens", Book::Genre::kFiction, Date(1861, Date::aug, 15)));
    add_book(lib, Book("7-8-9-F", "Fahrenheit 451", "Ray Bradbury", Book::Genre::kFiction, Date(1953, Date::oct, 19)));
    add_book(lib, Book("1-2-3-D", "The Diary of Anne Frank", "Anne Frank", Book::Genre::kBiography, Date(1947, Date::jun, 25)));
    add_book(lib, Book("4-5-6-E", "Einstein: His Life and Universe", "Walter Isaacson", Book::Genre::kBiography, Date(2007, Date::apr, 10)));
    add_book(lib, Book("7-8-9-S", "Steve Jobs", "Walter Isaacson", Book::Genre::kBiography, Date(2011, Date::oct, 24)));
    add_book(lib, Book("1-2-3-N", "National Geographic", "Various Authors", Book::Genre::kPeriodical, Date(1888, Date::oct, 1)));
    add_book(lib, Book("4-5-1-T", "Time Magazine", "Various Authors", Book::Genre::kPeriodical, Date(1923, Date::mar, 3)));
    add_book(lib, Book("7-8-9-A", "Alice's Adventures in Wonderland", "Lewis Carroll", Book::Genre::kChildren, Date(1865, Date::nov, 26)));
    add_book(lib, Book("1-2-3-P", "Peter Pan", "J.M. Barrie", Book::Genre::kChildren, Date(1911, Date::dec, 27)));
    add_book(lib, Book("4-5-6-W", "Winnie-the-Pooh", "A.A. Milne", Book::Genre::kChildren, Date(1926, Date::oct, 14)));
} 

void initialize_patrons(Library &lib)
{
    add_patron(lib, Patron("Bob Smith", 1234));
    add_patron(lib, Patron("Alice Johnson", 5678));
    add_patron(lib, Patron("Charlie Brown", 9012));
    add_patron(lib, Patron("Diana Miller", 3456));
    add_patron(lib, Patron("Ethan Davis", 7890));
    add_patron(lib, Patron("Fiona White", 2345));
    add_patron(lib, Patron("Gary Wilson", 6789));
    add_patron(lib, Patron("Helen Harris", 1235));
    add_patron(lib, Patron("Isaac Taylor", 5679));
    add_patron(lib, Patron("Jennifer Lee", 9013));
}

void initialize_check_out(Library &lib)
{
    Book book1("1-2-2-J", "Jurassic Park", "Micheal Crichton", Book::Genre::kNonFiction, Date(1990, Date::nov, 20));
    Book book2("1-2-3-J", "Jurassic Park Lost World", "Micheal Crichton", Book::Genre::kNonFiction, Date(1995, Date::sep, 8));
    Book book3("4-5-6-T", "The Time Traveler's Wife", "Audrey Niffenegger", Book::Genre::kFiction, Date(2003, Date::nov, 17));
    Book book4("4-5-6-C", "Catcher in the Rye", "J.D. Salinger", Book::Genre::kFiction, Date(1951, Date::jul, 16));

    Patron patron1("Bob Smith", 1234);
    Patron patron2("Alice Johnson", 5678);
    Patron patron3("Charlie Brown", 9012);
    Patron patron4("Diana Miller", 3456);

    check_out(lib, book1, patron1, Date(2016, Date::mar, 11));
    check_out(lib, book2, patron2, Date(2019, Date::jul, 22));
    check_out(lib, book3, patron3, Date(2019, Date::jan, 12));
    check_out(lib, book4, patron4, Date(2011, Date::oct, 14));
    
}

void print_library(const Library &lib) 
{
    cout << lib << '\n';
}

int main()
{
    try {
        my_lib::Library lib{};

        initialize_books(lib);
        initialize_patrons(lib);

        initialize_check_out(lib);

        print_library(lib);
    }
    catch(const exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
