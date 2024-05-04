#include "std_lib_facilities.h"

// Assume the elements within a sequence denotes a Set x of n elements.
// For ex: X = {a,b,c,d,e,f,g...}.
// The median depends on the cardinality of the set. 
// if n is odd, med(X) = X(n+1)/2
// if n is even, med(X) = (X(n/2) + X(n/2+1)) / 2;
//

int main()
{
    try {
       
        vector<double> temps;
        for(double temp; cin >> temp;) {
            temps.push_back(temp);
        }
        if(cin.eof()) error("EOF reached");

        double median = 0;
        int n = int(temps.size());
        if(n % 2) {
            median = temps[n/2];
        }
        else {
            median = (temps[n/2] + temps[n/2-1]) / 2.0;
        }

        cout << "The median value is " << median << '\n';
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
