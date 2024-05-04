#include <iostream>
#include <stdexcept>

class Int {
public:
    friend std::ostream& operator<<(std::ostream &os, const Int &rhs);

public:
    Int(int value = 0);
    ~Int() = default;

    Int(const Int &rhs);
    Int& operator=(const Int &rhs);

    int get() const;

private:
    int m_value;
};

Int::Int(int value)
    : m_value{value} 
{ }

Int::Int(const Int &rhs)
    : m_value{rhs.m_value} 
{ }

Int& Int::operator=(const Int &rhs)
{
    m_value = rhs.m_value;
    return *this;
}

int Int::get() const
{
    return m_value;
}

Int operator+(const Int &lhs, const Int &rhs)
{
    return {lhs.get() + rhs.get()};
}

Int operator-(const Int &lhs, const Int &rhs)
{
    return {lhs.get() - rhs.get()};
}

Int operator*(const Int &lhs, const Int &rhs)
{
    return {lhs.get() * rhs.get()};
}

Int operator/(const Int &lhs, const Int &rhs)
{
    return {lhs.get() / rhs.get()};
}

std::ostream& operator<<(std::ostream &os, const Int &rhs)
{
    return os << rhs.get();
}

int main()
{
    try {
       
        Int x{8};
        Int y{2};

        std::cout << "The sum of " << x.get() << " and " << y.get() << " is " << (x+y).get() << '\n';
        std::cout << "The difference of " << x.get() << " and " << y.get() << " is " << (x-y).get() << '\n';
        std::cout << "The product of " << x.get() << " and " << y.get() << " is " << (x*y).get() << '\n';
        std::cout << "The ratio of " << x.get() << " and " << y.get() << " is " << (x/y).get() << '\n';

        std::cout << "copy assignment operator:\n";
        x = y;
        if(x.get() == y.get()) {
            std::cout << "x and y are the same\n";
        }

        Int z = y;
        std::cout << "Copy constructor:\n";
        std::cout << "z = " << z.get() << " y = " << y.get() << '\n';

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
