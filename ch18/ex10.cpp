#include <cstring>
#include <iostream>
#include <stdexcept>

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
    int first = 0;
    int last = n-1;
    while (first < last) {
        if (s[first]!=s[last]) return false;
        ++first;
        --last;
    }

    return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max)
// read at most max–1 characters from is into buffer
{
    is.width(max);

    is >> buffer;

    if(std::strlen(buffer) >= max) throw std::runtime_error{"read_word: string is too large"};

    return is;
}

int main()
{
    try {
       
        constexpr int max = 5; // test
        for (char s[max]; read_word(std::cin,s,max);) {
            std::cout << s << " is";
            if (!is_palindrome(s,std::strlen(s))) std::cout << " not";
            std::cout << " a palindrome\n";
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
