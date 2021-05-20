#include "../include/std_lib_facilities.h"

// Version 9.7.4

enum class Month {
        kJan = 1, kFeb, kMar, kApr, kMay, kJun, kJul, kAug, kSep, kOct, kNov, kDec
};

class Date {
public:
    class Invalid{};                    // to throw an exception

    Date(int yy, Month mm, int dd);     // check for valid date and initialize

    Month month() const { return m; }   // const member: can't modify the object
    int day()     const { return d; }   // const member: can't modify the object
    int year()    const { return y; }   // const member: can't modify the object

    void add_day(int n);                // non-const member: can modify the object
    void add_month(int n);              // non-const member: can modify the object
    void add_year(int n);               // non-const member: can modify the object

private:
    int y;       // year
    Month m;     // month
    int d;       // day

    bool is_valid();
};

Date::Date(int yy, Month mm, int dd)
        :y{yy}, m{mm}, d{dd} {

    if(!is_valid()) throw Invalid{};
}

bool Date::is_valid() {
// check that (y,m,d) is a valid date.

    if(d < 1 || d > 31) return false;
    if(m < Month::kJan || m > Month::kDec) return false;

    return true;
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

void Date::add_month(int n) {
// add n to month

	int next_month{};
	if((next_month = int(m) + n) > 12) {
        m = Month::kJan;
		add_year(1);
	}
	else {
		m = Month(next_month);
    }
}

void Date::add_year(int n) {
// add n to year

    y += n;
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