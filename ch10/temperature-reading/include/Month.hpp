#ifndef MONTH_HPP
#define MONTH_HPP

#include "Day.hpp"

#include "std_lib_facilities.h"

const int not_a_month{-1};

const vector<string> month_input_tbl{
"jan", "feb", "mar", "apr", "may", "jun", "jul",
"aug", "sep", "oct", "nov", "dec"
};

const vector<string> month_print_tbl = {
"January", "February", "March", "April", "May", "June", "July",
"August", "September", "October", "November", "December"
};

struct Month {
    Month();

    int month{not_a_month}; // [0:11] January is 0
    vector<Day> days;   // [1:31] one vector of readings per day
};

int month_to_int(const string &s);
string int_to_month(int i);

istream& operator>>(istream &in, Month &m);

#endif
