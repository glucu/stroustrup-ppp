#include <iostream>
#include <string>

/*
 * Output:
 * Base constructor called for Base Object
 * Base constructor called for Derived Object
 * Derived constructor called for Derived Object
 *
 * Derived destructor called for Derived Object
 * Base destructor called for Derived Object
 * Base destructor called for Base Object
 */

class Base {
public:
    Base(const std::string& name) : name_(name) {
        std::cout << "Base constructor called for " << name_ << std::endl;
    }

    ~Base() {
        std::cout << "Base destructor called for " << name_ << std::endl;
    }

protected:
    std::string name_;
};

class Derived : public Base {
public:
    Derived(const std::string& name) : Base(name) {
        std::cout << "Derived constructor called for " << name_ << std::endl;
    }

    ~Derived() {
        std::cout << "Derived destructor called for " << name_ << std::endl;
    }
};

int main() {

    Base base("Base Object");
    Derived derived("Derived Object");

    return 0;
}
