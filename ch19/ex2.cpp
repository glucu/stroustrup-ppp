#include <iostream>
#include <string>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename T, typename U>
auto dot_product(const std::vector<T> &vt, const std::vector<U> &vu)
{
    static_assert(std::is_arithmetic_v<T>, "T failed is_arithmetic_v<T>");
    static_assert(std::is_arithmetic_v<U>, "U failed is_arithmetic_v<U>");

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
       
        std::vector<int> ivec;
        std::vector<double> dvec;
        for(int i{}; i != 10; ++i) {
            ivec.push_back(i);
            dvec.push_back(i*1.1);
        }

        std::cout << "Sum:\t" << dot_product(ivec, dvec) << '\n';

        /* This fails at compile-time. std::string is not an arithmetic type. Uncomment to try.
         *
        std::vector<std::string> svec{"A","B","C","D","E","F","G","H","I","J"};
        std::cout << "Sum:\t" << dot_product(svec,ivec) << '\n';
        */

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
