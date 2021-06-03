#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 4
 *
 * Modify the store_temps.cpp program from exercise 2 to include a temperature 
 * suffix c for Celsius or f for Fahrenheit temperatures. Then modify the temp_stats.cpp 
 * program to test each temperature, converting the Celsius readings to Fahrenheit before 
 * putting them into the vector.
 */

struct Reading {

    Reading(double t, int h, char ts) : temperature{t}, hour{h}, temp_suffix{ts} { }

    double temperature;   // in Fahrenheit
    int hour;             // hour after midnight [0:23]
    char temp_suffix;
};

constexpr int kMin_hour{0};
constexpr int kMax_hour{23};
constexpr int kMin_temp{-40};
constexpr int kMax_temp{115};
constexpr char kFah{'f'};
constexpr char kCel{'c'};

const std::string kFile_name{"raw_temps.txt"};

Reading create_reading() {
// create's ramdomly generated temperatures

    int hour{ randint(kMin_hour, kMax_hour) };
    double temp = randint(kMin_temp, kMax_temp) + randint(-10, 10) / double(10);
    char ts{' '};
    randint(0,10) > 4 ? ts = kFah : ts = kCel;
    return Reading{temp, hour, ts};
}

void write_file(const std::vector<Reading> &r) {
// write's vector r of readings to a file

    std::ofstream ost{kFile_name};
    if(ost.fail()) error("can't open file ", kFile_name);

    for(const auto &i : r) {
        ost << i.hour << ' ' << i.temperature << ' ' << i.temp_suffix << '\n';
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