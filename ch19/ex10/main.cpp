#include "unique_ptr.hpp"

#include <iostream>
#include <vector>

int main()
{
    unique_ptr<double> up{new double{3.14}};

    std::cout << "operator*():\n";
    std::cout << *up << '\n';

}
