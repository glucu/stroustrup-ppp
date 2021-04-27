#include "../include/std_lib_facilities.h"


/*  COMMENT:
 *  The problem made it seem that he wants us to use the binarry search technique
 *  There's 100 choices to choose from and 2^7 == 128, so 7 being the max number
 *  of guesses. I went with this approach.
 */

int main() {

    std::cout << "Please enter a number between 1-100 (followed by 'enter'):\n";
    int val{};
    std::cin >> val;

    if(val >= 1 && val <= 100) {

        int questions{};
        int lo{ 1 };
        int hi{ 100 };
        while(lo <= hi) {
            
            int computer_guess{ lo + (hi - lo) / 2 };

            std::cout << "Is the number you are thinking of " << computer_guess << " (y/n)?\n";
            char user_ans = ' ';
            std::cin >> user_ans;

            ++questions;

            switch(user_ans) {

            case 'y':
                std::cout << "I guessed right! It only took me " << questions << " guesse(s)!\n";
                return 0;
                break;
            case 'n':
                std::cout << "Is the number you are thinking of less than " << computer_guess << "?\n";
                std::cin >> user_ans;
                if(user_ans == 'y') {
                    ++questions;
                    hi = computer_guess;
                }
                else if(user_ans == 'n') {
                    lo = computer_guess + 1;
                }
                else {
                    std::cout << "Sorry, I don't understand your answer. Try again\n";
                }
                break;
            }

            computer_guess = (lo + hi) / 2;
        }
    }
    else {
        error("Invalid number");
    }

    return 0;
}