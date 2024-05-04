#include "Punct_stream.hpp"

int main()
{
    Punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    ps.case_sensitive(false);

    cout << "please enter words:\n";
    vector<string> vs;
    for(string word; ps >> word;) {
        vs.push_back(word);
    }

    sort(vs);

    for(size_t i{}; i != vs.size(); ++i) {
        if(i == 0 || vs[i] != vs[i-1]) cout << vs[i] << '\n';
    }
}
