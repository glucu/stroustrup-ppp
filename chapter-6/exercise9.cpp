#include "../include/std_lib_facilities.h"

/* Chapter 6: exercise 9
 * 
 * Write a program that reads digits and composes them into integers. For
 * example, 123 is read as the characters 1, 2, and 3. The program should
 * output "123 is 1 hundred and 2 tens and 3 ones". The number should be
 * output as an int value. Handle numbers with one, two, three, or four
 * digits. Hint: To get the integer value 5 of the character '5' subtract '0',
 * that is, '5'-'0'==5.  
 */

int main() {

    constexpr char quit{'q'};

    const std::vector<std::string> words{"ones", "tens", "hundred", "thousand"};
    std::vector<int> digits;
    int count{};
    char number{'?'};
    
    std::cout << "Enter up to four digits:\n";
    std::cin >> number;
    int digit{ number - '0' };
        
    digits.push_back(digit);
    while(std::cin >> number && number != quit) {
        ++count;
        digits.push_back(number-'0');
    }

    for(const int d : digits)
        std::cout << d;
    std::cout << " is ";

    for(int i = 0; i < digits.size(); ++i) {
        if(i < digits.size()-1) {
            std::cout << digits[i] << ' ' << words[count] << " and ";
        }
        else {
            std::cout << digits[i] << ' ' << words[count] << ".\n";
        }
        --count;
    }
}