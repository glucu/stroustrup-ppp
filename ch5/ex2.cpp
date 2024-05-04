#include "std_lib_facilities.h"

// Errors that were found:
// 1. The type of k should be a double and not an int.
// 2. the return should be returning the variable k
// 3. cin is reading into a undefined variable d. Should be c.
// 4. argument passed to the ctok function should be the variable c
// 5. Cout should be cout


double ctok(double c)
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;
    cin >> c;
    double k = ctok(c);
    cout << k << '\n';
} 
