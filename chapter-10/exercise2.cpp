#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 2
 *
 * Write a program that creates a file of data in the form of the temperature
 * Reading type defmed in §10.5. Fill the file with at least 50 temperature
 * readings. Call this program store_temps.cpp and the file it creates
 * raw_temps.txt.
 */

struct Reading {

    Reading(double t, int h) : temperature{t}, hour{h} { }

    double temperature;   // in Fahrenheit
    int hour;             // hour after midnight [0:23]
};

constexpr int kMin_hour{0};
constexpr int kMax_hour{23};
constexpr int kMin_temp{-40};
constexpr int kMax_temp{115};

const std::string kFile_name{"raw_temps.txt"};

Reading create_reading() {
// create's ramdomly generated temperatures

    int hour{ randint(kMin_hour, kMax_hour) };
    double temp = randint(kMin_temp, kMax_temp) + randint(-10, 10) / double(10);
    return Reading{temp, hour};
}

void write_file(const std::vector<Reading> &r) {
// write's vector r of readings to a file

    std::ofstream ost{kFile_name};
    if(ost.fail()) error("can't open file ", kFile_name);

    for(const auto &i : r) {
        ost << i.hour << ' ' << i.temperature << '\n';
    }
}

int main() {

    try {

        std::vector<Reading> reading;
        for(int i{}; i < 50; ++i) {
            reading.push_back(create_reading());
        }

        write_file(reading);

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