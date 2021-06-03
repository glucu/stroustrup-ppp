#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 3
 *
 * Write a program that reads the data from raw_temps.txt created in
 * exercise 2 into a vector and then calculates the mean and median temperatures 
 * in your data set. Call this program temp_stats.cpp. 
 */

struct Reading {

    Reading(double t, int h) : temperature{t}, hour{h} { }

    double temperature;   // in Fahrenheit
    int hour;             // hour after midnight [0:23]
};

bool operator<(const Reading &lhs, const Reading &rhs) {

    return lhs.temperature < rhs.temperature;
}

constexpr int kMin_hour{0};
constexpr int kMax_hour{23};

const std::string kFile_name{"raw_temps.txt"};

std::vector<Reading> read_file() {

    std::vector<Reading> temp;
    std::ifstream ist{kFile_name};
    if(ist.fail()) error("can't open file ", kFile_name);

    int h{};
    double t{};
    while(ist >> h >> t) {
        if(h < kMin_hour || h > kMax_hour) error("hour out of range");
        temp.push_back(Reading{t, h});
    }

    return temp;
}

double calculate_mean(const std::vector<Reading> &r) {

    double sum{};
    for(const auto &t : r) {
        sum += t.temperature;
    }

    return sum / r.size();
}

double calculate_median(const std::vector<Reading> &r) {

    int n = r.size();
    double mid{};
    if(n % 2 > 0) {
        mid = r[n / 2].temperature;
    }
    else {
        mid = (r[mid].temperature + r[n / 2 - 1].temperature) / 2;
    }

    return mid;
}

int main() {

    try {

        std::vector<Reading> reading{ read_file() };

        double mean{ calculate_mean(reading) };

        std::sort(reading.begin(), reading.end());
        double median{ calculate_median(reading) };

        std::cout << "median temperature: " << median << " F\n";
        std::cout << "average temperature: " << mean << " F\n";

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