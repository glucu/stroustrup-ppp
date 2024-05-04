#include "std_lib_facilities.h"

int factorial(int n)
// calculate the factorial of n
// pre-condition: n must be a non-negative
{
    if(n < 0) error("factorial of a negative number", n);

    int result{1};
    while(n > 0) {
        result *= n;
        --n;
        if(result < 1) error("factorial overflow");
    }
    return result;
}

int n_permutations(int a, int b)
// calculate the permutations of P(a,b)
{
    if(a < 0 || b < 0 || b > a) error("bad permutation");
    return factorial(a) / factorial(a-b);
}

int n_combinations(int a, int b)
{
    return n_permutations(a,b) / factorial(b);
}

int main()
{
    try {

        char again{};
        do {

            cout << "I can calculate the number of combinations and permutations for sets of numbers\n"
	             << "Please enter two numbers (separated by whitespace)\n"
	             << "first the number of elements in the set and then the number of elements in a subset thereof:\n";
            int a{}, b{};
            cin >> a >> b;
            if(cin) {
                cout << "Now, enter \'c\' to compute combinations\n\'p\' to compute permutations: ";
                int result{};
                bool is_combi{};
                bool is_perm{};
                char op{};
                cin >> op;
                switch(op) {
                    case 'c':
                    case 'C':
                        result = n_combinations(a,b);
                        is_combi = true;
                        break;
                    case 'p':
                    case 'P':
                        result = n_permutations(a,b);
                        is_perm = true;
                        break;
                    default:
                        cout << op << " is not an option. Try again.\n";
                        break;
                }

                if(is_combi) {
                    cout << "C(" << a << ',' << b << ") = " << result << '\n';
                }
                if(is_perm) {
                    cout << "P(" << a << ',' << b << ") = " << result << '\n';
                }

                cout << "\nTry again? (y/n): ";
                cin >> again;
                if(cin.eof()) error("Reached End of File");
            }
            else {
                if(cin.eof()) error("Reached End of File");

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInteger was not read. Try again.\n";
            }

        } while(toupper(again) != 'N');

        keep_window_open();
        return 0;
    }
    catch(exception &e) {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...) {
        cerr << "exception\n";
        keep_window_open();
        return 2;
    }
}
