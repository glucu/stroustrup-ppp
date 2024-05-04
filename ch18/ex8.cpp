#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

const std::string kQuit{"q!"};

bool is_palindrome(const std::string &s)
{
    std::string s_cpy;
    for(size_t i{}; i != s.size(); ++i) {
        s_cpy.push_back(s[s.size()-1-i]);
    }

    return s_cpy == s;
}

bool is_palindrome(const char s[], int n)
// s points to the first character of an array of n characters
{
    char s_cpy[n];
    for(int i{}; i != n; ++i) {
        s_cpy[i] = s[n-1-i];
        if(s_cpy[i] != s[i]) return false;
    }

    return true;
}

bool is_palindrome(const char *first, const char *last)
// first points to the first letter, last to the last letter
{
    int cpy_n = last - first + 2;
    char *cpy = new char[cpy_n];
    for(int i{}; i != cpy_n; ++i) {
        cpy[i] = first[(last-first)-i];
        
        if(cpy[i] != first[i]) {
            delete[] cpy;
            return false;
        }
    }
    delete[] cpy;
    return true;
}

void string_palindrome()
{
    for(std::string s; std::cin >> s && s != kQuit;) {
        std::cout << s << " is";
        if(!is_palindrome(s)) std::cout << " not";
        std::cout << " a palindrome\n";
    }
}

std::istream& read_word(std::istream &is, char *buffer, int max)
{
    is.width(max);
    is >> buffer;

    return is;
}

void array_palindrome()
{
   constexpr int max = 128;
   for(char s[max]; read_word(std::cin, s, max) && s != kQuit;) {
       std::cout << s << " is";
       if(!is_palindrome(s, std::strlen(s)))
           std::cout << " not";
       std::cout << " a palindrome\n";
   }
}

void pointer_palindrome()
{
   constexpr int max = 128;
   for(char s[max]; read_word(std::cin, s, max) && s != kQuit;) {
       std::cout << s << " is";
       if(!is_palindrome(&s[0], &s[std::strlen(s)-1]))
           std::cout << " not";
       std::cout << " a palindrome\n";
   }
}

int main()
{
    try {
       
        string_palindrome();
        array_palindrome();
        pointer_palindrome();

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
