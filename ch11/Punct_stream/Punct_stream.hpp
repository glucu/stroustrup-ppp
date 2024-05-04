#ifndef PUNCT_STREAM_HPP
#define PUNCT_STREAM_HPP

#include "std_lib_facilities.h"

class Punct_stream {
public:
    Punct_stream(istream &is);

    void whitespace(const string &s);
    void add_white(char ch);
    void case_sensitive(bool b);
    
    bool is_whitespace(char c) const;
    bool is_case_sensitive() const;

    Punct_stream& operator>>(string &s);
    operator bool();

private:
    istream &m_source;
    istringstream m_buffer;
    string m_white;
    bool m_sensitive;
};

#endif
