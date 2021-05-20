#include "../include/std_lib_facilities.h"


enum class Month {
        kJan = 1, kFeb, kMar, kApr, kMay, kJun, kJul, kAug, kSep, kOct, kNov, kDec
};

class Date {
public:
    Date(int yy, Month mm, int dd);   // check for valid date and initialize
    void add_day(int n);              // increase the Date by n days
    Month month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }

private:
    int y;       // year
    Month m;     // month
    int d;       // day
};

// check that (y,m,d) is a valid date. If it is,
// use it to initialize dd
Date::Date(int yy, Month mm, int dd) 
    : y{yy}, m{mm}, d{dd} {

    if(m < Month::kJan || m > Month::kDec) error("Date(): invalid month");
    if(d < 1 || d > 31) error("Date(): invalid day");
}

void Date::add_day(int n) {
// increments date's day by n days
// if d += n exceeds 31, set d to 1 and increment month by one

    if((d += n) > 31) {

		d = 1;
		int next_month{ int(m) + 1 };
		if(next_month > 12) {

			m = Month::kJan;
		}
		else {
			m = Month(next_month);
        }
	}
}


std::ostream& operator<<(std::ostream &os, const Date &date) {
// prints out date in (y, m, d) format

    return os << '(' << int(date.month())
              << ',' << date.day()
              << ',' << date.year() << ')';
}


int main() {

    try {

        // valid date
        Date today{1978, Month::kJun, 25};
	    Date tomorrow{today};
        
        tomorrow.add_day(1);

        std::cout << "Today's date: " << today << '\n';
        std::cout << "Tomorrow's date: " << tomorrow << '\n';

        // invalid date
        Date invalid_date{2004, Month::kDec, -5};

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