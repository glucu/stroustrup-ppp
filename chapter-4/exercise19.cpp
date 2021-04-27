#include "../include/std_lib_facilities.h"

/*   COMMENT:
 *   I combined exercises 19, 20, and 21 together here.
 *   Of course, I could be passing the vectors by const-reference; however,
 *   I am going by what has been taught so far in the book. References hasn't
 *   been covered yet. 
 */


std::vector<std::string> names;
std::vector<int> scores;

const std::string quit{ "NoName" };

bool check_duplicate_name(const std::string &name) {

    for(const auto &n : names) {
        if(name == n) return true;
    }

    return false;
}

const std::string read_name() {

    std::cout << "Enter name: ";
    std::string name;
    std::cin >> name;
    if(check_duplicate_name(name)) {
        error("Detected duplicate name.");
    }
    else {

        return name;
    }
}

const int read_score() {

    std::cout << "Enter score: ";
    int score{};
    std::cin >> score;
    
    return score;
}

void print_names() {

    for(size_t i{}; i < names.size(); ++i) {

        std::cout << '(' << names[i] << ',' << scores[i] << ")\n";
    }
}

int get_score(const std::string name) {

    for(size_t i{}; i < names.size(); ++i) {
        if(name == names[i]) return scores[i];
    }

    return -1;
}

void list_names(int score) {

    bool exits{};
    for(size_t i{}; i < scores.size(); ++i) {
        if(score == scores[i]) {
            exits = true;
            std::cout << names[i] << '\n';
        }
    }

    if(!exits) {
        std::cout << "score not found.\n";
    }
}

int main() {

    std::cout << "Please enter a series of name-value pairs " 
              << "followed by 'NoName 0' to quit:\n\n";

    std::string name;
    int score{};
    name = read_name();
    score = read_score();
    while(name != quit) {

        names.push_back(name);
        scores.push_back(score);

        name = read_name();
        score = read_score();
    }
    std::cout << '\n';

    print_names();

    std::cout << "\nEnter name or score (name = 'n', score = 's', or 'q' to quit):\n";
    char answer{' '};
    while(std::cin >> answer && answer != 'q') {

        switch(answer) {

        case 'n':
            std::cout << "Enter name: ";
            std::cin >> name;
            score = get_score(name);
            if(score != -1) {
                std::cout << name << " score is " << score << '\n';
            }
            else {
                std::cout << "name not found.\n";
            }
            break;

        case 's':
            std::cout << "Enter score: ";
            std::cin >> score;
            list_names(score);
            break;

        default:
            std::cout << "Sorry, incorrect choice. Try again.\n";
            break;
        }
    }

    return 0;
}