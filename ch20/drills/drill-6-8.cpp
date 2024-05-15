#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <list>
#include <type_traits>

template <typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(; f1 != e1; ++f1, ++f2) {
        *f2 = *f1;
    }
    return f2;
}

template <typename Cont>
inline void print_elements(const Cont &coll, const std::string &name)
{
    std::cout << name;
    for(const auto &elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main()
{
    try {
       
        int arr[]{0,1,2,3,4,5,6,7,8,9};
        std::list<int> l;
        l.resize(10);
        std::vector<int> v;
        v.resize(10);
        my_copy(std::cbegin(arr), std::cend(arr), v.begin());
        my_copy(v.cbegin(), v.cend(), l.begin());
        print_elements(v, "vector: ");

        if(auto iter = std::find(v.cbegin(), v.cend(), 3); iter != v.cend()) {
            std::cout << *iter << " found at position " << std::distance(v.cbegin(), iter) + 1 << '\n';
        }
        else {
            std::cout << "Value was not found\n";
        }

        if(auto iter = std::find(l.cbegin(), l.cend(), 27); iter != l.cend()) {
            std::cout << *iter << " found at position " << std::distance(l.cbegin(), iter) + 1 << '\n';
        }
        else {
            std::cout << "Value was not found\n";
        }

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