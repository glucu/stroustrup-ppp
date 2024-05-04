#include "Punct_stream.hpp"

Punct_stream::Punct_stream(istream &is)
    : m_source{is}, m_sensitive{true} {}

void Punct_stream::whitespace(const string &s)
// make s the whitespace set
{
    m_white = s;
}

void Punct_stream::add_white(char c)
// add to the whitespace set
{
    m_white += c;
}

bool Punct_stream::is_whitespace(char c) const
// is c in the whitespace set?
{
    for(char w : m_white) {
        if(c == w) return true;
    }
    return false;
}

void Punct_stream::case_sensitive(bool b) 
// set whether input is case sensitive
{
    m_sensitive = b;
}

bool Punct_stream::is_case_sensitive() const
// is the input case sensitive? 
{
    return m_sensitive;
}

Punct_stream& Punct_stream::operator>>(string &s)
{
    while(!(m_buffer >> s)) {
        if(m_buffer.bad() || !m_source.good()) return *this;

        m_buffer.clear();

        string line;
        getline(m_source, line);

        for(char &c : line) {
            if(is_whitespace(c)) {
                c = ' ';
            }
            else if(!m_sensitive) {
                c = tolower(c);
            }
        }

        m_buffer.str(line);
    }
    return *this;
}

Punct_stream::operator bool()
{
    return !(m_source.fail() || m_source.bad()) && m_source.good();
}


