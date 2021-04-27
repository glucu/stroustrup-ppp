#include "../include/std_lib_facilities.h"

int main() {

    std::vector<double> temps;
    for(double temp; std::cin >> temp;) {
        temps.push_back(temp);
    }

    sort(temps);
    int mid = temps.size() / 2;
    if(temps.size() % 2 != 0) {
        std::cout << "Median temperature: " << temps[mid] << '\n';
    }
    else {
        std::cout << "Median temperature: " << (temps[mid] + temps[mid-1]) / 2 << '\n';
    }

    return 0;
}