#include "std_lib_facilities.h"

int main()
{
    try {
       
        int num_cents = 0;
        cout << "How many pennies do you have? ";
        int pennies = 0;
        cin >> pennies;

        num_cents += pennies * 1;

        cout << "How many nickels do you have? ";
        int nickels = 0;
        cin >> nickels;

        num_cents += nickels * 5;

        cout << "How many dimes do you have? ";
        int dimes = 0;
        cin >> dimes;

        num_cents += dimes * 10;

        cout << "How many quarters do you have? ";
        int quarters = 0;
        cin >> quarters;

        num_cents += quarters * 25;

        cout << "How many half dollars do you have? ";
        int half_dollars = 0;
        cin >> half_dollars;

        num_cents += half_dollars * 50;

        if(pennies > 0) {
            cout << "You have " << pennies;
            if(pennies > 1) {
                cout << " pennies.\n";
            }
            else {
                cout << " penny.\n";
            }
        }
        if(nickels > 0) {
            cout << "You have " << nickels;
            if(nickels > 1) {
                cout << " nickels.\n";
            }
            else {
                cout << " nickel.\n";
            }
        }
        if(dimes > 0) {
            cout << "You have " << dimes;
            if(dimes > 1) {
                cout << " dimes.\n";
            }
            else {
                cout << " dime.\n";
            }
        }
        if(quarters > 0) {
            cout << "You have " << quarters;
            if(quarters > 1) {
                cout << " quarters.\n";
            }
            else {
                cout << " quarter.\n";
            }
        }
        if(half_dollars > 0) {
            cout << "You have " << half_dollars;
            if(half_dollars > 1) {
                cout << " half dollars.\n";
            }
            else {
                cout << " half dollar.\n";
            }
        }

        cout << "The value of all of your coins is " << num_cents << " cents.\n";
        cout << "The sum in dollars is " << double(num_cents) / 100 << '\n';

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
