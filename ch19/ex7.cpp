#include "Number/Number.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T, typename U>
auto dot_product(const std::vector<T> &vt, const std::vector<U> &vu)
{
    static_assert(std::is_arithmetic_v<T> || std::is_class_v<T>, "T failed is_arithmetic_v<T>");
    static_assert(std::is_arithmetic_v<T> || std::is_class_v<T>, "T failed is_arithmetic_v<T>");

    if(vt.size() != vu.size()) {
        throw std::logic_error{"vectors must be of the same size"};
    }

    std::common_type_t<T,U> sum{};
    for(std::size_t i{}; i != vt.size(); ++i) {
        sum += vt[i] * vu[i];
    }
    return sum;
}

int main()
{
    try {
       
        std::vector<Number<double>> nvec1, nvec2;
        for(std::size_t i{}; i != 10; ++i) {
            nvec1.push_back(Number<double>{i*1.1});
            nvec2.push_back(Number<double>{i*1.1});
        }

        std::cout << "Sum:\t" << dot_product(nvec1, nvec2) << '\n';

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
