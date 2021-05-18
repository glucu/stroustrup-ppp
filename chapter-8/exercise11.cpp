#include "../include/std_lib_facilities.h"


/* Chapter 8: exercise 11
 *
 * Write a function that finds the smallest and the largest element of a
 * vector argument and also computes the mean and the median. Do not
 * use global variables. Either return a struct containing the results or pass
 * them back through reference arguments. Which of the two ways of returning several result values do you prefer and why?
 */

/* COMMENT:
 * I prefer the use of a struct and then returning a struct with the results calculated.
 * I find it more clear, concise, less error-prone, but more obscure.  
 */

struct Stats {

    double min{};
    double max{};
    double mean{};
    double median{};
};

void print_stats(const Stats &s) {

    std::cout << "Statistics:\n\n"
              << "Min:\t" << s.min << '\n'
              << "Max:\t" << s.max << '\n'
              << "Mean:\t" << s.mean << '\n'
              << "Median:\t" << s.median << '\n';
}

double minv(const std::vector<double> &numbers) {
// find and return the smallest element found in the vector numbers.
// pre-condition: size of vector numbers must be at least one.

    if(numbers.size() == 0) error("minv(): pre-condition violated");

    double min{numbers[0]};
    for(size_t i{1}; i < numbers.size(); ++i) {
        if(min > numbers[i]) min = numbers[i];
    }

    return min;
}

double maxv(const std::vector<double> &numbers) {
// find and return the largest element found in the vector numbers.
// pre-condition: size of vector numbers must be at least one.

    if(numbers.size() == 0) error("maxv(): pre-condition violated");

    double max{numbers[0]};
    for(size_t i{1}; i < numbers.size(); ++i) {
        if(max < numbers[i]) max = numbers[i];
    }

    return max;
}

double calc_mean(const std::vector<double> &numbers) {
// return the average value by adding up all of the numbers
// and divide by the number of numbers in vector numbers.

    double sum{};
    for(const auto &num : numbers) {
        sum += num;
    }

    return sum / numbers.size();
}

double calc_median(std::vector<double> &numbers) {
// return the middle element of the sorted vector numbers.

    std::sort(numbers.begin(), numbers.end());

    int n = numbers.size();
    if (n % 2 != 0) {
        return numbers[n / 2];
    }

     return (numbers[(n - 1) / 2] + numbers[n / 2]) / 2.0;
}


const Stats calculate(std::vector<double> &numbers) {

    double min{ minv(numbers) };
    double max{ maxv(numbers) };
    double mean{ calc_mean(numbers) };
    double median{calc_median(numbers) };

    return {min, max, mean, median};
}

void ignoreLine() {
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::vector<double> read_numbers() {
// allows the user to enter a set of numbers
// to computer thier own statistics.

    std::vector<double> temp;
    for(double val; std::cin >> val;) {
        temp.push_back(val);
    }

    return temp;
}


int main() {

    try {

        std::cout << "Please enter a set of numbers (followed by a non-number to exit):\n";
        std::vector<double> numbers{ read_numbers() };
        Stats stats{ calculate(numbers) };
        print_stats(stats);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}