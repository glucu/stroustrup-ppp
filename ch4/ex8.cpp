#include "std_lib_facilities.h"

int get_user_input()
{
    while(true) {
        int grains = 0;
        cin >> grains;
        if(cin) {
            if(grains == 1'000 || grains == 1'000'000 || grains == 1'000'000'000) {
                return grains;
            }
            cout << "The amount of grains entered is incorrect. Try again.\n";
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            if(cin.eof()) error("EOF reached");
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid read. Please try again.\n";
        }
    }
}

int main()
{
    try {
        
        cout << "Calculating the number of squares needed base on the amount of grains entered.\n"
             << "Please enter the number of grains (1,000, 1,000,000, or 1,000,000,000):\n";
        int total_grains = get_user_input(); 
        int square = 0;
        int grain = 1;
        for(; grain <= total_grains; grain *= 2) {
            ++square;
            cout << "Square #" << square << " == " << grain << " grains.\n";
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
