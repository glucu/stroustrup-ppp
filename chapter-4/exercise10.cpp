#include "../include/std_lib_facilities.h"

constexpr char rock{'r'}, paper{'p'}, scissor{'s'};
constexpr int max_score{2};

int main() {

    std::cout << "How many different moves should the computer have?\n";
    int pc_moves{};
    std::cin >> pc_moves;
    if(pc_moves < 1)
        error("Number of moves must be greater than one!");
    
    std::vector<char> pc;
    std::cout << "Enter the computer moves as either 'r', 'p' or 's':\n";
    for(int i{}; i < pc_moves; ++i) {
        char m{};
        std::cin >> m;
        if(m == 'r' || m == 'p' || m == 's') {
            pc.push_back(m);
        }
        else {
            std::cout << "Sorry, try again:\n";
            --i;
        }
    }

    int user_score{};
    int pc_score{};
    char pc_guess{};
    int iter{};

    std::cout << "Lets play a game called, Rock, Paper, Scissors!\n";
    std::cout << "Rock == 'r', Paper = 'p' and Scissors = 's'.\n";
    std::cout << "First to reach 3 wins!\n\n";

    std::cout << ">> ";
    char user_ans{};
    std::cin >> user_ans;
    while(user_score != max_score && pc_score != max_score) {

        if(user_ans != rock && user_ans != paper && user_ans != scissor) {
            std::cout << "oops, try again:\n";
        }
        else {

            pc_guess = pc[iter];
            ++iter;
            switch(pc_guess) {
            
            case rock:
                switch(user_ans) {

                case rock:
                    std::cout << "It's a tie!\n";
                    break;
                case paper:
                    ++user_score;
                    std::cout << "I win!\n";
                    break;
                case scissor:
                    ++pc_score;
                    std::cout << "You win!\n";
                    break;
                }
                break;
            case paper:
                 switch(user_ans) {
                 case rock:
                    ++pc_score;
                    std::cout << "You win!\n";
                    break;
                 case paper:
                    std::cout << "It's a tie!\n";
                    break;
                 case scissor:
                    ++user_score;
                    std::cout << "I win!\n";
                    break;
                }
                break;
            case scissor:
                 switch(user_ans) {

                 case rock:
                    ++user_score;
                    std::cout << "I win!\n";
                    break;
                 case paper:
                    ++pc_score;
                    std::cout << "You win!\n";
                    break;
                 case scissor:
                    std::cout << "It's a tie!\n";
                    break;
                }
                break; 
            }

            std::cout << ">> ";
            std::cin >> user_ans;
        }
    }

    if(user_score == 2) {
        std::cout << "Human person won!\n";
    }
    else {
        std::cout << "You have been beaten by a computer! :(\n";
    }

    return 0;
}