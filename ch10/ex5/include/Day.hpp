#ifndef DAY_HPP
#define DAY_HPP

#include "std_lib_facilities.h"

const int not_a_reading{-7777}; // less than absolute zero

struct Day {
    Day();
    vector<double> hours;
};

#endif
