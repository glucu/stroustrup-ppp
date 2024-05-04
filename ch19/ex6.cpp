#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T> class Number;

template <typename T> std::ostream& operator<<(std::ostream &os, const Number<T> &rhs);
template <typename T> bool operator==(const Number<T> &lhs, const Number<T> &rhs);
template <typename T> bool operator!=(const Number<T> &lhs, const Number<T> &rhs);
template <typename T> bool operator<(const Number<T> &lhs, const Number<T> &rhs);
template <typename T> bool operator<=(const Number<T> &lhs, const Number<T> &rhs);
template <typename T> bool operator>(const Number<T> &lhs, const Number<T> &rhs);
template <typename T> bool operator>=(const Number<T> &lhs, const Number<T> &rhs);

template <typename T>
class Number {

    static_assert(std::is_arithmetic_v<T>, "T is not an arithmetic type!");

public:
    friend std::ostream& operator<< <>(std::ostream &os, const Number &rhs);
    friend bool operator== <>(const Number &lhs, const Number &rhs);
    friend bool operator!= <>(const Number &lhs, const Number &rhs);
    friend bool operator< <>(const Number &lhs, const Number &rhs);
    friend bool operator<= <>(const Number &lhs, const Number &rhs);
    friend bool operator> <>(const Number &lhs, const Number &rhs);
    friend bool operator>= <>(const Number &lhs, const Number &rhs);

public:
    Number(T value = T{});
    ~Number() = default;

    Number(const Number &rhs);
    Number& operator=(const Number &rhs);

    T get() const;

    Number& operator+=(const Number &rhs);
    Number& operator-=(const Number &rhs);
    Number& operator*=(const Number &rhs);
    Number& operator/=(const Number &rhs);
    Number& operator%=(const Number &rhs);

private:
    T m_value;
};

template <typename T>
Number<T>::Number(T value)
    : m_value{value}
{ }

template <typename T>
Number<T>::Number(const Number &rhs)
    : m_value{rhs.m_value}
{ }

template <typename T>
Number<T>& Number<T>::operator=(const Number &rhs)
{
    m_value = rhs.m_value;
    return *this;
}

template <typename T>
T Number<T>::get() const
{
    return m_value;
}

template <typename T>
Number<T>& Number<T>::operator+=(const Number<T> &rhs)
{
    m_value += rhs.m_value;
    return *this;
}

template <typename T>
Number<T>& Number<T>::operator-=(const Number<T> &rhs)
{
    m_value -= rhs.m_value;
    return *this;
}

template <typename T>
Number<T>& Number<T>::operator*=(const Number<T> &rhs)
{
    m_value *= rhs.m_value;
    return *this;
}

template <typename T>
Number<T>& Number<T>::operator/=(const Number<T> &rhs)
{
    m_value /= rhs.m_value;
    return *this;
}

template <typename T>
Number<T>& Number<T>::operator%=(const Number<T> &rhs)
{
    m_value %= rhs.m_value;
    return *this;
}

template <typename T>
Number<T> operator+(const Number<T> &lhs, const Number<T> &rhs)
{
    return {lhs.get() + rhs.get()};
}

template <typename T>
Number<T> operator-(const Number<T> &lhs, const Number<T> &rhs)
{
    return {lhs.get() - rhs.get()};
}

template <typename T>
Number<T> operator*(const Number<T> &lhs, const Number<T> &rhs)
{
    return {lhs.get() * rhs.get()};
}

template <typename T>
Number<T> operator/(const Number<T> &lhs, const Number<T> &rhs)
{
    return {lhs.get() / rhs.get()};
}

template <typename T>
Number<T> operator%(const Number<T> &lhs, const Number<T> &rhs)
{
    return {lhs.get() % rhs.get()};
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const Number<T> &rhs)
{
    return os << rhs.get();
}

template <typename T>
bool operator==(const Number<T> &lhs, const Number<T> &rhs)
{
    return lhs.get() == rhs.get();
}

template <typename T>
bool operator!=(const Number<T> &lhs, const Number<T> &rhs)
{
    return !(lhs.get() == rhs.get());
}

template <typename T>
bool operator<(const Number<T> &lhs, const Number<T> &rhs)
{
    return lhs.get() < rhs.get();
}

template <typename T>
bool operator<=(const Number<T> &lhs, const Number<T> &rhs)
{
    return lhs.get() <= rhs.get();
}

template <typename T>
bool operator>(const Number<T> &lhs, const Number<T> &rhs)
{
    return lhs.get() > rhs.get();
}

template <typename T>
bool operator>=(const Number<T> &lhs, const Number<T> &rhs)
{
    return lhs.get() >= rhs.get();
}

int main()
{
    try {

        Number<int> num{10};
        std::cout << num << '\n';

        Number<double> numd{10.5};
        std::cout << numd << '\n';

        num = num + 5;
        std::cout << num << '\n';

        double i = num.get();
        std::cout << i << '\n';

        num = 101;
        num = num % 2;
        std::cout << num << '\n';

        num %= 2;
        std::cout << num << '\n';


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
