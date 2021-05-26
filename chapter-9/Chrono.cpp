#include "Chrono.h"

namespace chrono {
// member function definitions:

    Date::Date(int y, Month m, int d)
         : y{y}, m{m}, d{d} {
         
         if(!is_date(y, m, d)) throw Invalid{};
    }

    const Date& default_date() {
        static Date dd{2001, Month::kJan, 1};   // start of 21st century
        return dd;
    }

    Date::Date() 
         :y{default_date().year()},
          m{default_date().month()},
          d{default_date().day()}
    { }

    void Date::add_day(int n) {
        
        // ...
    }

    void Date::add_month(int n) {

        // ...
    }

    void Date::add_year(int n) {

        if(m == Month::kFeb && d == 29 && !leapyear(y+n)) {   // beware of leap years!
            m = Month::kMar;                                  // use March 1 instead of February 29
            d = 1;
        }

        y += n;
    }

    // helper functions:

    bool is_date(int y, Month m, int d) {
        // assume that y is valid

        if(d <= 0) return false;        // d must be positive
        if(m < Month::kJan || Month::kDec < m) return false;

        int days_in_month{ 31 };        // most months have 31 days

        switch(m) {
        case Month::kFeb:               // the length of February varies
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;
        case Month::kApr: case Month::kSep: case Month::kNov:
            days_in_month = 30;         // the rest have 30 days
            break;
        }

        if(days_in_month < d) return false;

        return true;
    }

    bool leapyear(int y) {
        
        return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
    }

    bool operator==(const Date &a, const Date &b) {

        return a.year() == b.year()
               && a.month() == b.month()
               && a.day() == b.day();
    }

    bool operator!=(const Date &a, const Date &b) {

        return !(a==b);
    }

    std::ostream& operator<<(std::ostream &os, const Date &d) {

        return os << '(' << d.year()
                  << ',' << int(d.month())
                  << ',' << d.day() << ')';
    }
    std::istream& operator>>(std::istream &is, Date &dd) {

        int y{}, m{}, d{};
        char ch1{}, ch2{}, ch3{}, ch4{};
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if(!is) return is;
        if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {   // oops: format error
            is.clear(std::ios_base::failbit);                        // set the fail bit
            return is;
        }

        dd = Date{ y, Month(m), d };                                 // update dd

        return is;
    }

    enum class Day {
        kSunday, kMonday, kTuesday, kWednesday, kThursday, kFriday, kSaturday
    };

    
    Day day_of_week(const Date &d) {

        // ...
    }

    Date next_Sunday(const Date &d) {

        // ...
    }

    Date next_weekday(const Date &d) {

        // ...
    }
    
    
}   // namespace chrono