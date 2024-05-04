#ifndef YEAR_HPP
#define YEAR_HPP

#include "Month.hpp"

#include "std_lib_facilities.h"

struct Year {                 // a year of temperature readings, organized by month
    Year();
    int year;                 // positive == A.D
    vector<Month> months; // [0:11] January is 0
};

istream& operator>>(istream &in, Year &y);

#endif
