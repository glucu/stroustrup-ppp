#include "../include/std_lib_facilities.h"

// Version 9.4.1

struct Date {

    int y;   // year
    int m;   // month
    int d;   // day
};

void add_day(Date &date) {
// increments date's day by one

    ++date.d;
}

void init_day(Date &dd, int y, int m, int d) {
// check that (y,m,d) is a valid date. If it is,
// use it to initialize dd

    if(m < 1 || m > 12) error("init_day(): Invalid month");
    if(d < 1 || d > 31) error("init_day(): Invalid day");

    dd = Date{y, m, d};   // assumes year is valid
}

std::ostream& operator<<(std::ostream &os, const Date &date) {
// prints out date in (y, m, d) format

    return os << '(' << date.m 
              << ',' << date.d
              << ',' << date.y << ')';
}

int main() {

    try {

        // valid date
        Date today;
        init_day(today, 1978, 6, 25);

        Date tomorrow{today};
        add_day(tomorrow);

        std::cout << "Today's date: " << today << '\n';
        std::cout << "Tomorrow's date: " << tomorrow << '\n';

        // invalid date
        Date invalid_date;
        init_day(invalid_date, 2004, 13, -5);

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