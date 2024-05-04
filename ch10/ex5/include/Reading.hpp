#ifndef READING_HPP
#define READING_HPP

#include "std_lib_facilities.h"

struct Reading {
    int day;
    int hour;
    double temperature;
};

bool is_valid(const Reading &r);

istream& operator>>(istream &in, Reading &r);

#endif
