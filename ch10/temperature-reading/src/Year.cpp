#include "../include/Year.hpp"
#include "../include/Month.hpp"
#include "../include/functions.hpp"

Year::Year() : months(12) {} 

istream& operator>>(istream &in, Year &y) 
// read a Year from in into y
// format: { year y ... }
{
    char ch;
    if(in >> ch && ch != '{') {
        in.unget();
        in.clear(ios_base::failbit);
        return in;
    }
    if(in.eof()) return in;

    string year_maker;
    int yy;
    in >> year_maker >> yy;
    if(!in || year_maker != "year") error("bad start of year");
    y.year = yy;

    while(true) {
        Month m;
        if(!(in >> m)) break;
        y.months[m.month] = m;
    }

    end_of_loop(in, '}', "bad end of year");
    return in;
}
