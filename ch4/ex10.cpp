#include "std_lib_facilities.h"

// COMMENT:
// Sorry, Real randomness is too hard to learn right now, but I couldn't bypass without doing it :D
// 


const vector<char> moves{'r', 'p', 's'};
const int kPc_moves{10};

vector<char> initialize()
{
    vector<char> v;
    random_device rd; // a seed source for the random number engine
    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(0, int(moves.size() - 1));
    for(size_t i = 0; i != kPc_moves; ++i) {
        v.push_back(moves[distrib(gen)]);
    }
    return v;
}

char get_user_input()
{
    bool is_move = false;
    char usr_move = ' ';
    while(!is_move) {
        is_move = false;
        cout << "\nEnter move: ";
        cin >> usr_move;
        if(cin) {
            for(size_t i = 0; i != moves.size(); ++i) {
                if(moves[i] == usr_move) {
                    is_move = true;
                }
            }
            if(!is_move) cout << usr_move << " is an invalid move. Try again.\n";
        }
        else if(cin.eof()) error("EOF reached");
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return usr_move;
}

bool check_round_winner(char usr, char pc) 
{
    return ((usr == 'r' && pc == 's') || (usr == 'p' && pc == 'r') ||
            (usr == 's' && pc == 'p'));
}

int main()
{
    try {
        
        cout << "Welcome to Rock-Paper-Scissors Game!\n"
             << "Please enter your choice (\'r\', \'p\', or \'s\'): \n";
        vector<char> pc_moves = initialize();
        size_t pc_idx = 0;
        int pc_score = 0;
        int usr_score = 0;
        int round = 1;
        while(round <= 3) {
            char pc_move = pc_moves[pc_idx++]; 
            char usr_move = get_user_input();
            bool is_winner = check_round_winner(usr_move, pc_move);
            if(is_winner) {
                ++usr_score;
                cout << "User won round #" << round << "!\n"
                     << "User move: " << usr_move << " - " << "PC move: " << pc_move << "\n\n";
            }
            else if(usr_move == pc_move) {
                cout << "Tied round!\n"
                     << "User move: " << usr_move << " - " << "PC move: " << pc_move << "\n\n";
                --round;
            }
            else {
                ++pc_score;
                cout << "PC won round #" << round << "!\n"
                     << "User move: " << usr_move << " - " << "PC move: " << pc_move << "\n\n";
            }
         
            ++round;
        }
        cout << '\n';

        if(usr_score == pc_score) {
            cout << "Both of you tied!\n";
        }
        else if(usr_score > pc_score) {
            cout << "User wins!\n"
                << "User score: " << usr_score << " - " << "PC score: " << pc_score << '\n';
        }
        else {
            cout << "Computer wins!\n"
                 << "User score: " << usr_score << " - " << "PC score: " << pc_score << '\n';
        }


        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
