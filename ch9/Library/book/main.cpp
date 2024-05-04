#include "Book.hpp"

#include "std_lib_facilities.h"

using my_lib::Book;
using Chrono::Date;

void print_book(const Book &b) 
{
    cout << b << '\n';
}

int main()
{
    try {
       
        Book b1("1-2-3-J", "Jurassic Park", "Micheal Crichton", Book::Genre::kNonFiction, Date(1990, Date::Month::nov, 20));
        Book b2("3-2-1-J", "Jurassic Park Lost World", "Micheal Crichton", Book::Genre::kNonFiction, Date(1995, Date::Month::sep, 8));

        cout << "Books:\n";
        print_book(b1);
        print_book(b2);


        if(b1 == b2) cout << b1.title() << " and " << b2.title() << " are the same books.\n";
        if(b1 != b2) cout << b1.title() << " and " << b2.title() << " are not the same books.\n";
        
        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
