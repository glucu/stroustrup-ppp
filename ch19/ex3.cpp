#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T, typename U>
struct Pair {
public:
    Pair(const T &t = T{}, const U &u = U{})
        : name{t}, value{u} { }

    T name;
    U value;
};

class Symbol_table {
public:
    Symbol_table() = default;
    ~Symbol_table() = default;

    double get(const std::string &) const;
    void set(const std::string &, double);
    bool is_declared(const std::string &) const;
    double declare(const std::string &, double);

private:
    std::vector<Pair<std::string, double>> m_var_table;
};

double Symbol_table::get(const std::string &n) const
{
    for(const auto &v : m_var_table) {
        if(v.name == n) return v.value;
    }
    throw std::runtime_error{"get: undefined Variable"};
}

void Symbol_table::set(const std::string &n, double d)
{
    for(auto &v : m_var_table) {
        if(v.name == n) {
            v.value = d;
            return;
        }
    }
    throw std::runtime_error{"set: Undefined Variable"};
}

bool Symbol_table::is_declared(const std::string &n) const
{
    for(const auto &v : m_var_table) {
        if(v.name == n) return true;
    }
    return false;
}

double Symbol_table::declare(const std::string &n, double d)
{
    if(is_declared(n)) throw std::runtime_error{"declare: undefined variable"};
    m_var_table.push_back(Pair<std::string, double>{n,d});
    return d;
}

int main()
{
    try {
       
        Symbol_table st;
        st.declare("Pi",3.14);
        st.declare("e",2.72);
        std::cout << "Pi is " << st.get("Pi") << "\n";

        if (st.is_declared("Pi"))
            std::cout << "Pi is declared\n";
        else
            std::cout << "Pi is not declared\n";

        if (st.is_declared("nd"))
            std::cout << "nd is declared\n";
        else
            std::cout << "nd is not declared\n";
        
        st.set("Pi",4.14);
        std::cout << "Pi is now " << st.get("Pi") << "\n";
        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
