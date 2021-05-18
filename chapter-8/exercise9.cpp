#include "../include/std_lib_facilities.h"


/* Chapter 8: exercise 9
 * 
 * Write a function that given two vector<double>s price and weight computes a value 
 * (an "index") that is the sum of all price[i]*weight[i]. Note that we must have weight.size()==price.size().
 */

double inner_product(const std::vector<double> &price, std::vector<double> &weight) {
// computes an index that is the sum of all price[i] * weight[i]
// pre-condition: weight.size() == price.size()

    if(price.size() != weight.size()) error("inner_product(): pre-condition violated");

    double sum{};
    for(size_t i{}; i < price.size(); ++i) {
        sum += price[i] * weight[i];
    }

    return sum;
}


int main() {

    try {

        std::vector<double> price{7, 4, 3, 39, 31, 10, 2, 30, 26, 19};
        std::vector<double> weight{5, 22, 15, 12, 49, 36, 3, 1, 7, 17};

        double sum{ inner_product(price, weight) };
        std::cout << "sum: " << sum << '\n';
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