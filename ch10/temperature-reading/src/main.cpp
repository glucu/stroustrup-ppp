#include "../include/Year.hpp"
#include "std_lib_facilities.h"

/*
 * COMMENT:
 * I could had kept all of the struct classes in a single file. However, I want to get use to with the idea of
 * modularity, that way if a problem arises, I can look at the headers or specific source files to narrow down the search.
 * Also note the <b>operator>>(istream &in, const Reading &r)</b> function. I ended up changing the logic part of it because
 * whenever the istream trys to read a negative temperature, it ends up extracting the minus (-) sign as a seperate character 
 * from the rest of the number. This would cause the istream state to fail causing an exception to be thrown. Because of this,
 * I had to modify the function a bit to deal with this case. There might be a better way but I don't want to waste more time
 * on this exercise.
 */

void print_day(ostream &os, const Day &d, size_t dd)
{
    for(size_t i{}; i != d.hours.size(); ++i) {
        if(d.hours[i] != not_a_reading) {
            os << " (" << dd << ' ' << i << ' ' << d.hours[i] << ")";
        }
    }
}

void print_month(ostream &os, const Month &m)
{
    if(m.month != not_a_month) {
        os << "{ " << "month " << int_to_month(m.month);
        for(size_t i{1}; i != m.days.size(); ++i) {
            print_day(os, m.days[i], i);
        }
        os << " } ";
    }
}

void print_year(ostream &os, const Year &y)
{
    if(y.year >= 1) {
        os << "{ year " << y.year << ' ';
        for(size_t i{}; i != y.months.size(); ++i) {
            print_month(os, y.months[i]);
        }
        os << "}\n";
    }
}

int main() 
{
    try {
        // open an input file:
        cout << "Please enter input file name:\n";
        string iname{"input.txt"};
        cin >> iname;
        ifstream ist{iname};
        if(!ist) error("can't open input file ", iname);

        ist.exceptions(ist.exceptions() | ios_base::badbit);

        // open an output file:
        cout << "Please enter output file name:\n";
        string oname;
        cin >> oname;
        ofstream ost{oname};
        if(!ost) error("can't open output file", oname);

        // read an arbitrary number of years:
        vector<Year> years;
        while(true) {
            Year y;
            if(!(ist >> y)) break;
            years.push_back(y);
        }
        cout << "Read " << years.size() << " years of readings\n";

        for(const Year &y : years) print_year(ost, y);
    }
    catch(const exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "exception: something went wrong\n";
        return 2;
    }
}

