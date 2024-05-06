#include <iostream>
#include <string>

class Tracer {
public:
    Tracer(const std::string& s) : m_message(s) { std::cout << "Constructed " << m_message << "\n"; }
    Tracer(const Tracer& t) : m_message(t.m_message)
    {
        std::cout << "Copy constructed from " << m_message << "\n";
    }

    ~Tracer() { std::cout << "Destroyed " << m_message << "\n"; }

    Tracer& operator=(const Tracer &t)
    {
        m_message = t.m_message;
        std::cout << "Copy assigned " << m_message << "\n";
        return *this;
    }

    void set_message(const std::string &s) { m_message = s; }

private:
    std::string m_message;
};

void testLocalObjects()
{
    Tracer local1{"local1"};
    Tracer local2{"local2"};
    {
        Tracer local3{"local3"};
    }
}

class MyClass {
public:
    MyClass() : member1("member1"), member2("member2") {}

private:
    Tracer member1;
    Tracer member2;
};

Tracer global1{"global1"};

void testDynamicAllocation()
{
    Tracer* ptr1 = new Tracer{"dynamic1"};
    Tracer* ptr2 = new Tracer{"dynamic2"};
    delete ptr1;
    delete ptr2;
}

int main()
{
    Tracer global2{"global2"};
    testLocalObjects();

    MyClass obj;

    testDynamicAllocation();

    return 0;
}
