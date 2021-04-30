#include "../include/std_lib_facilities.h"

/*  Chapter 5: exercise 14
 *
 *  Read (day-of-the-week,value) pairs from standard input. For example :
 * 
 *  Tuesday 23 Friday 56 Tuesday -3 Thursday 99
 * 
 *  Collect all the values for each day of the week in a vector<int>. Write out
 *  the values of the seven day-of-the-week vectors. Print out the sum of the
 *  values in each vector. Ignore illegal days of the week, such as Funday, but
 *  accept common synonyms such as Mon and monday. Write out the number of rejected values. 
 */


const std::vector<std::string> valid_days {
    "Sunday", "sunday", "sun", "Sun", "Sun.", "sun.",
    "Monday", "monday", "mon", "Mon", "Mon.", "mon.",
    "Tuesday", "tuesday", "tues", "Tues", "Tues.", "tues.",
    "Wednesday", "wednesday", "wed", "Wed", "Wed.", "wed.",
    "Thursday", "thursday", "thurs", "Thurs", "Thurs.", "thurs.",
    "Friday", "friday", "fri", "Fri", "Fri.", "fri.",
    "Saturday", "saturday", "sat", "Sat", "Sat.", "sat.",
};

const std::string bad_input_error{"read_day_of_the_week_pairs(): coudn't read an integer value"};
const std::string failed_read_error{"print_values(): pre-condition violation"};

bool check_day(const std::string &day) {
// Returns true if valid day detected; otherwise
// retuns false

    for(const std::string d : valid_days) {
        if(day == d) return true;
    }

    return false;
}

int read_day_of_the_week_pairs(std::vector<int> &values) {
// Read in day of the week and value pairs. Returns
// the number of rejected days
// pre-condition: day of the week must be a valid
//                day according to the valid_days vector

    int rejected_days{};
    std::string day;
    int value{};
    while(std::cin >> day >> value) {

        bool found{ check_day(day) };
        if(found) {
            values.push_back(value);
        }
        else {
            std::cout << "Rejected " << day << ' ' << value << " pair since " 
                      << day << " is not a day of the week!\n";
            ++rejected_days;
        }
    }

    if(std::cin.eof()) return rejected_days;
    else               error(bad_input_error);
}

void print_values(const std::vector<int> &values) {
// Prints the values from day-of-the-week pairs.
// pre-condition:  At least one pair entered.

    if(values.size() < 1) error(failed_read_error);

    for(const int val : values) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int sum_of_days(const std::vector<int> &values) {
// Adds all the values from day-of-the-week pairs.

    int sum{};
    for(const int val : values) {
        sum += val;
    }

    return sum;
}

int main() {

    try {

        std::cout << "Please enter a day of the week and value pairs:\n";
        std::cout << "Example: Tuesday 23 Friday 56 Tuesday -3 Thursday 99\n";
        std::cout << "Enter Ctrl-D or Ctrl-Z to stop.\n\n";

        std::vector<int> values;
        int rejected_days{ read_day_of_the_week_pairs(values) };

        std::cout << "\nThe values of the seven day-of-the-week are:\n";
        print_values(values);

        std::cout << "The sum of the values are:\n";
        std::cout << sum_of_days(values) << '\n';

        std::cout << "The number of rejected days are:\n";
        std::cout << rejected_days << '\n';

        return 0;
    }
    catch(const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong.\n";
        return 2;
    }
}