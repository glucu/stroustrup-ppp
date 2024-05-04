#include "std_lib_facilities.h"

int main()
{
    try {
        
        cout << "Please enter a whitespace-separated sequence of doubles (representing distances between two cities along a given route)\n";
        vector<double> dists;
        for(double dist; cin >> dist;) {
            if(dist < 1) cout << "negative distance entered. Try again.\n";
            else 
                dists.push_back(dist);
        }
        if(dists.size() == 0) error("You didn't enter any values");

        double min_dist = dists[0];
        double max_dist = dists[0];
        double sum = 0;
        for(double dist : dists) {
           sum += dist;
           if(dist < min_dist) min_dist = dist;
           if(dist > max_dist) max_dist = dist;
        }

        cout << "The sum of all distances is " << sum << '\n'
             << "The smallest distance between two neighboring cities is " << min_dist << '\n'
             << "The largest distance between two neighboring cities is " << max_dist << '\n'
             << "The mean of all distances is " << sum / dists.size() << '\n';
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
