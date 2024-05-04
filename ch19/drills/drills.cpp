#include <iostream>
#include <vector>

template <typename T> struct S {
public:
    S(T v = T{}) 
        : val{v} { }

    S& operator=(const T &s);

    T& get();
    const T& get() const;

private:
    T val;
};

template <typename T>
T& S<T>::get()
{
    return val;
}

template <typename T>
const T& S<T>::get() const
{
    return val;
}

template <typename T>
S<T>& S<T>::operator=(const T &t)
{
    val = t;
}

template <typename T> std::ostream& print(const S<T> &s, std::ostream &os = std::cout)
{
    return os << s.get();
}

template <> std::ostream& print<std::vector<int>>(const S<std::vector<int>> &s, std::ostream &os)
{
    for(const auto &elem : s.get()) {
        os << elem << ' ';
    }
    return os;
}

template <typename T>
void read_val(T &t)
{
    std::cin >> t;
}

template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> std::istream& operator>>(std::istream& is, std::vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    std::vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(std::ios_base::failbit);
        return is;
    }
    while (std::cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(std::ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp);

    d = v_temp;
}

int main()
{
    S<int> si{27};
    S<char> sc{'G'};
    S<double> sd{3.14};
    S<std::string> ss{"C++ rules!"};
    S<std::vector<int>> sv{{0,1,2,3,4,5,6,7,8,9}};

    print(si); std::cout << '\n';
    print(sc); std::cout << '\n';
    print(sd); std::cout << '\n';
    print(ss); std::cout << '\n';
    print<std::vector<int>>(sv); std::cout << '\n';

}


