#include "../include/Month.hpp"
#include "../include/Reading.hpp"
#include "../include/functions.hpp"

Month::Month() : month{not_a_month},
                 days(32) { }

istream& operator>>(istream &in, Month &m) 
// read a month from in into m
// format: { month feb ... }
{
    char ch = 0;
    if(in >> ch && ch != '{') {
        in.unget();
        in.clear(ios_base::failbit);
        return in;
    }

    string month_maker;
    string mm;
    in >> month_maker >> mm;
    if(!in || month_maker != "month") error("bad start of month");
    m.month = month_to_int(mm);

    Reading r{};
    int duplicates{};
    int invalids{};
    while(in >> r) {
        if(is_valid(r)) {
            if(m.days[r.day].hours[r.hour] != not_a_reading) {
                ++duplicates;
            }
            m.days[r.day].hours[r.hour] = r.temperature;
        }
        else {
            ++invalids;
        }
    }
    
    if(invalids) error("invalid readings in month", invalids);
    if(duplicates) error("duplicate readings in month", duplicates);
    end_of_loop(in, '}', "bad end of month");
    return in;
}

void end_of_loop(iostream &in, char term, const string &message)
{
    if(in.fail()) {
        in.clear();
        char ch;
        if(in >> ch && ch == term) return;
        error(message);
    }
}

    
int month_to_int(const string &s)
// is s the name of a month? if so, return its index [0:11] otherwise -1
{
    for(int i{}; i != month_input_tbl.size(); ++i) {
            if(month_input_tbl[i] == s) return i;
    }
    return -1;
}

string int_to_month(int i)
// months [0:11]
{
    if(i < 0 || 12 <= i) error("bad month index");
    return month_print_tbl[i];
}

