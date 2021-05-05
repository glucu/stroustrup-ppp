#include "../include/std_lib_facilities.h"

/* Chapter 6: exercise 4
 *
 * Defme a class Name_value that holds a string and a value. 
 * Give it a constructor (a bit like Token). Rework exercise 19 in Chapter 4 to use a
 * vector< Name_ value> instead of two vectors.
 */

class Name_value {
public:
    Name_value(const std::string &n, int v)
        : name{n}, value{v} { }

    std::string name;
    int value;
};

std::vector<Name_value> nv;

const std::string quit{ "NoName" };

bool check_duplicate_name(const std::string &name) {

    for(const auto &n : nv) {
        if(name == n.name) return true;
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

    for(size_t i{}; i < nv.size(); ++i) {

        std::cout << '(' << nv[i].name << ',' << nv[i].value << ")\n";
    }
}

int get_score(const std::string name) {

    for(size_t i{}; i < nv.size(); ++i) {
        if(name == nv[i].name) return nv[i].value;
    }

    return -1;
}

void list_names(int score) {

    bool exits{};
    for(size_t i{}; i < nv.size(); ++i) {
        if(score == nv[i].value) {
            exits = true;
            std::cout << nv[i].name << '\n';
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

        Name_value t{name, score};
        nv.push_back(t);

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