#include "../include/Day.hpp"

Day::Day() : hours(24)
{
    for(size_t i{}; i != hours.size(); ++i) hours[i] = not_a_reading;
}
