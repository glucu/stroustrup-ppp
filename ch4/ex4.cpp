#include "std_lib_facilities.h"

int main()
{
    try {

        int low = 1;
        int high = 100;
        int usr_number = 0;       
        cout << "Please enter a number between " << low << " and " << high << " and I will try and guess your number in no more than " << 7 << " tries.\n";
        while(cin >> usr_number) {
            if(usr_number < 1 || usr_number > 100) {
                cout << "Please enter a number between " << low << " and " << high << ".\n";
            }
            else {
                int guesses = 0;
                bool found = false;
                while(low <= high) {
                    int middle = floor((low + high) / 2);
                    cout << "Is the number you are thinking of " << middle << " (y/n)? ";
                    ++guesses;

                    char usr_answer = ' ';
                    cin >> usr_answer;
                    if(usr_answer == 'y') {
                        found = true;
                        break;
                    }
                    else {
                        cout << "Is the number you are thinking of less than " << middle << " (y/n)? ";
                        cin >> usr_answer;
                        if(usr_answer == 'y') {
                            high = middle - 1;
                        }
                        else {
                            low = middle + 1;
                        }
                    }
                }

                if(found) {
                    cout << "I guessed your number in " << guesses;
                    if(guesses > 1) cout << " tries!\n";
                    else          cout << " try!\n";
                }
                else {
                    cout << "I failed to guess your number. Lucky you! >:(\n";
                }

                cout << "Play again? (y/n): ";
                char again;
                cin >> again;
                if(again != 'y') break;

                low = 1;
                high = 100;
                cout << "Please enter a number between " << low << " and " << high << " and I will try and guess your number in no more than " << 7 << " tries.\n"; 
            }
        }

        if(cin.eof()) error("EOF reached");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
