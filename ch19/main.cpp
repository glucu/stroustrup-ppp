#include "vector.hpp"

#include <iostream>

template <typename T>
void show_info(const vector<T> &v) 
{
    std::cout << "size:\t\t" << v.size() << '\n'
              << "capacity:\t" << v.capacity() << "\n\n";
}

template <typename T>
void copy_cont(vector<T> vec)
{
    vector<double> cpy{vec};
    show_info(cpy);
}

int main()
{
    std::cout << '\n';

    std::cout << "Default constructor:\n";
    vector<double> vd{};
    show_info(vd);

    std::cout << "Append 10 elements:\n";
    for(std::size_t i{}; i != 10; ++i) {
        vd.push_back(i+1.1);
    }
    std::cout << "Elements:\n";
    std::cout << vd << '\n';
    show_info(vd);

    std::cout << "Copy constructors:\n";
    copy_cont(vd);

    std::cout << "Copy assignment:\n";
    vd = vector<double>{9,9,9,9,9};
    std::cout << vd << '\n';
    show_info(vd);
    std::cout << "Add one more element:\n";
    vd.push_back(100);
    std::cout << vd << '\n';
    show_info(vd);

    std::cout << "Move constructor:\n";
    vector<double> vec{std::move(vd)};
    std::cout << vec << '\n';
    show_info(vec);

    std::cout << "veci:\n";
    vector<int> veci{};
    veci.reserve(150);
    show_info(veci);
    std::cout << '\n';
    veci.push_back(55);
    show_info(veci);
    std::cout << veci << '\n';

    std::cout << "Test for at():\n";
    std::cout << veci.at(0) << '\n';

}