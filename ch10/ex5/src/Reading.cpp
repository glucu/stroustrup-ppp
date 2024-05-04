#include "../include/Reading.hpp"

#include "std_lib_facilities.h"

istream& operator>>(istream &in, Reading &r)
// read a temperature reading from in into r
// format: ( d h t ) 
// check format, but don't bother with data validity
{
    char ch1;
    if(in >> ch1 && ch1 != '(') {
        in.unget();
        in.clear(ios_base::failbit);
        return in;
    }

    char ch2;
    int d;
    int h;
    bool is_sign{};
    double t;
    in >> d >> h;
    if(in.get() == '-') is_sign = true;
    in >> t >> ch2;
    if(!in || ch2 != ')') error("bad reading");
    r.day = d;
    r.hour = h;
    if(is_sign) t = -t;
    r.temperature = t;
    return in;
}

const int implausible_min{-200};
const int implausible_max{200};

bool is_valid(const Reading &r) 
// a rough test
{
    if(r.day < 1 || 31 < r.day) return false;
    if(r.hour < 0 || 23 < r.hour) return false;
    if(r.temperature < implausible_min || implausible_max < r.temperature)
        return false;
    return true;
}

