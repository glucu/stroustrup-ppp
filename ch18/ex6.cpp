#include <iostream>
#include <stdexcept>
#include <string>

std::string cat_dot(const std::string &s1, const std::string &s2, const std::string &separator = ".")
{
    return s1 + separator + s2;
}

int main()
{
    try {

        for(std::string s1, s2, s3; std::cin >> s1 >> s2 >> s3;) {
            std::cout << cat_dot(s1,s2, s3) << '\n';
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
