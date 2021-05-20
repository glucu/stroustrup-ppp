#include "../include/std_lib_facilities.h"

// Version 9.4.3

class Date {
public:
    Date(int yy, int mm, int dd);   // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }

private:
    int y, m, d;                    // year, month, day
};

// check that (y,m,d) is a valid date. If it is,
// use it to initialize dd
Date::Date(int yy, int mm, int dd) 
    : y{yy}, m{mm}, d{dd} {

    if(m < 1 || m > 12) error("Date(): invalid month");
    if(d < 1 || d > 31) error("Date(): invalid day");
}

void Date::add_day(int n) {
// increments date's day by n days
// if d += n exceeds 31, set d to 1 and increment month by one

    if((d += n) > 31) {
        d = 1;
        ++m;
    }
    else {
        d += n;
    }
}


std::ostream& operator<<(std::ostream &os, const Date &date) {
// prints out date in (y, m, d) format

    return os << '(' << date.month()
              << ',' << date.day()
              << ',' << date.year() << ')';
}

int main() {

    try {

        // valid date
        Date today{1978, 6, 25};
	    Date tomorrow{today};
        
        tomorrow.add_day(1);

        std::cout << "Today's date: " << today << '\n';
        std::cout << "Tomorrow's date: " << tomorrow << '\n';

        // invalid date
        Date invalid_date{2004, 13, -5};

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}