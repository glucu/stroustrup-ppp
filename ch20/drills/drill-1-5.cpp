#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <iterator>

template <typename Cont>
void func(Cont &coll)
{
    for(auto &elem : coll) {
        elem += 2;
    }
}

template <typename Cont>
void print_elements(const Cont &coll, const std::string &name)
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

        int arr1[]{0,1,2,3,4,5,6,7,8,9};
        std::vector<int> v1(std::cbegin(arr1), std::cend(arr1));
        std::list<int> l1(v1.cbegin(), v1.cend());

        int arr2[10];
        std::copy(std::cbegin(arr1), std::cend(arr1), arr2);
        std::vector<int> v2{v1};
        std::list<int> l2{l1};

        func(arr2);
        func(v2);
        func(l2);

        print_elements(arr2, "array: ");
        print_elements(v2, "vector: ");
        print_elements(l2, "list: ");

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
