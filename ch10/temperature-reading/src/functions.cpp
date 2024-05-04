#include "../include/functions.hpp"

void end_of_loop(istream &in, char term, const string &message)
{
    if(in.fail()) {
        in.clear();
        char ch;
        if(in >> ch && ch == term) return;
        error(message);
    }
}
