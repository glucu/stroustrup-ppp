#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <vector>

template <typename T>
void f(std::vector<T> &v1, const std::vector<T> &v2)
{
    for(std::size_t i{}; i != v1.size(); ++i) {
        if(i == v2.size()) break;
        v1[i] += v2[i];
    }
}

template <>
void f(std::vector<const char*> &v1, const std::vector<const char*> &v2)
{
    for(std::size_t i{}; i != v1.size(); ++i) {
        if(i == v2.size()) break;
        std::string tmp{v1[i]};
        tmp += v2[i];
        v1[i] = strdup(tmp.c_str());
    }
}

template <typename T>
void print(const std::vector<T> &v)
{
    for(const auto &elem : v) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main()
{
    try {
       
        std::vector<int> v1{0,1,2,3,4,5};
        std::vector<int> v2{0,1,2,3,4,5};
        f(v1,v2);
        print(v1);

        std::vector<double> v3{1.1,2.2,3.3,4.4,5.5};
        std::vector<double> v4{1.1,2.2,3.3,4.4,5.5};
        f(v3,v4);
        print(v3);

        std::vector<std::string> v5{"A","B","C","D"};
        std::vector<std::string> v6{"A","B","C","D"};
        f(v5,v6);
        print(v5);

        std::vector<char> v7{'C','+','+'};
        std::vector<char> v8{'C'};
        f(v7,v8);
        print(v7);

        std::vector<const char*> v9{"C","+","+"};
        std::vector<const char*> v10{"C","+","+"};
        f(v9,v10);
        print(v9);
        

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
