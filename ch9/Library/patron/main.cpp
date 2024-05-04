#include "Patron.hpp"
#include "Chrono.hpp";

#include "std_lib_facilities.h"

using my_lib::Patron;
using Chrono::Date;

void print_patron(const Patron &p)
{
    cout << p << '\n';
}

int main()
{
    try {
       
        Patron p1("John Doe", 12345);
        Patron p2("Ashley Smith", 456421);

        print_patron(p1);
        print_patron(p2);

        p1.set_fee(123.43);

        if(p1.owes_fee()) cout << p1.name() << " owes $" << p1.fees() << '\n';


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
