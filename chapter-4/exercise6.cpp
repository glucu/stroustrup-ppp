#include "../include/std_lib_facilities.h"

int main() {

    const std::vector<std::string> words{"zero", "one", "two", "three", "four",
                                         "five", "six", "seven", "eight", "nine"};

    std::cout << "Enter a digit (0-9) and I will display its spelled-out number:\n";
    int digit{};
    char quit{ 'n' };
    while(std::cin >> digit) {

        if(digit < 0 || digit >= words.size()) {
            std::cout << "Sorry, number must be a single-digit. Try again:\n";
        }
        else {
            int spelled_word{ (digit + 10) % 10 };
            std::cout << words[spelled_word] << '\n';
            
            std::cout << "Now, enter a spelled-out number:\n";
            std::string word;
            std::cin >> word;
            for(int i = 0; i < words.size(); ++i) {
                
                if(word == words[i]) {

                    std::cout << i << '\n';
                }
            }

            std::cout << "Enter a digit and I will display its spelled-out number:\n";
        }   
    }

    return 0;
}
