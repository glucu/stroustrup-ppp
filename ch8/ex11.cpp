#include "std_lib_facilities.h"

/*
 * COMMENT:
 * The exercise wants us to write a single function that computes the smallest, largest, mean, and median.
 * Now, even though a function should do one logical thing. This really should be split into 4 functions
 * that each performs a distinct computation, but exercise says otherwise. 
 * 
 * Either return a Struct containing the results or pass them back through reference arguments. Which of the two 
 * ways of returning several result values do you prefer and why?
 *
 * I think returning a Struct is most suited. This expresses the intent more clearly that we are returning
 * a struct that will contain answers. Passing them as references to the function is another way, sure, but
 * I think it will make it less obvious unless you were to look at the definition of the function. What if
 * this function was placed elsewhere which you don't have easy access to view? 
 */

struct Result {
    double min{};
    double max{};
    double mean{};
    double median{};
};

double calc_mean(const vector<double> &v)
// compute the mean of the elements in v
{
    double sum = 0.0;
    for(double x : v) {
        sum += x;
    }
    return sum / v.size();
}

double calc_median(const vector<double> &v)
// compute the median of the elements in v
{

    double median;
    size_t n = v.size();
    if(n % 2) {
        median = v[n/2];
    }
    else {
        median = (v[n/2-1] + v[n/2]) / 2.0;
    }
    return median;
}


Result calculate(const vector<double> &v)
// calculate the minimum, maximum, mean, and median of the 
// elements of v
// pre-condition: the size of v must be at least one
{
    if(v.size() == 0) error("the number of the elements must be at least one");
    
    vector<double> tmp(v);
    sort(tmp);
    double min = tmp[0];
    double max = tmp[v.size() - 1];
    double mean = calc_mean(tmp);
    double median = calc_median(tmp);

    return {min, max, mean, median};
}

vector<double> get_numbers()
// read in a series of floating-point numbers
{
    vector<double> tmp;
    for(double val; cin >> val;) {
        tmp.push_back(val);
    }
    return tmp;
}

void print(const Result &res, const string &label)
{
    cout << label << ": \n";
    cout << "Min:\t" << res.min << '\n'
         << "Max:\t" << res.max << '\n'
         << "Mean:\t" << res.mean << '\n'
         << "Median:\t" << res.median << '\n';
}


int main()
{
    try {
        
        cout << "Please enter a series of floating-point numbers separated by a space (followed by a non-digit to stop:\n";
        vector<double> numbers = get_numbers();

        Result res = calculate(numbers);

        print(res, "STATISTICS");

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
