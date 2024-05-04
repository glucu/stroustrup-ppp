#include "std_lib_facilities.h"

constexpr int kMax_readings{50};
constexpr int kMin_hour{1};
constexpr int kMax_hour{24};
constexpr double kMin_temp{-200};
constexpr double kMax_temp{200};
const string kFile_name{"raw_temps.txt"};

struct Reading {
    int hour;
    double temperature;
};

vector<Reading> generate_readings()
{
    default_random_engine ran;
    vector<Reading> tmps;
    for(size_t i{}; i != kMax_readings; ++i) {
        int hour = uniform_int_distribution<int>{kMin_hour, kMax_hour}(ran);
        double temp = uniform_real_distribution<double>{kMin_temp, kMax_temp}(ran);
        tmps.push_back(Reading{hour, temp});
    }
    return tmps;
}

void write_to_file(const vector<Reading> &readings, const string &name)
{
    ofstream ost{name};
    if(!ost) error("Failed to open file for write ", name);

    for(Reading r : readings) {
        ost << r.hour << ' ' << r.temperature << '\n';
    }
}

int main()
{
    try {
       
        vector<Reading> readings = generate_readings(); 
        write_to_file(readings, kFile_name);
        
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
