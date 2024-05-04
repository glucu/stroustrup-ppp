#include "std_lib_facilities.h"

constexpr int kMin_hour{1};
constexpr int kMax_hour{24};
constexpr double kMin_temp{-200};
constexpr double kMax_temp{200};
const string kFile_name{"raw_temps.txt"};

struct Reading {
    int hour{};
    double temperature{};
};

istream& operator>>(istream &in, Reading &r)
{
    int h{};
    double t{};
    in >> h >> t;
    if(!in) error("bad reading");
    if(h < kMin_hour || kMax_hour < h ||
       t < kMin_temp || kMax_temp < t) error("bad reading of hour or temperature");

    r.hour = h;
    r.temperature = t;
    return in;
}

struct Stats {
    double mean{};
    double median{};
};

ostream& operator<<(ostream &os, const Stats &s)
{
    os << "STATISTICS: \n"
       << "MEAN:\t" << s.mean << '\n'
       << "MEDIAN:\t" << s.median;
}

vector<Reading> read_from_file(const string &name)
{
    ifstream ist{name};
    if(!ist) error("Failed to read from ", name);

    int h;
    double t;
    vector<Reading> tmps;
    while(ist >> h >> t) {
        tmps.push_back(Reading{h,t});
    }
    cout << "Finished reading " << tmps.size() << "(hour, temperature) "
         << "pairs from file " << kFile_name << '\n';
    
    return tmps;
}

double compute_mean(const vector<Reading> &readings)
// compute the mean of the temperatures in readings
// pre-condition: the size of readings must be at least one
//                to protect from potential divide-by-zero
{
    if(readings.size() == 0) error("compute_mean: size of readings is zero");
    double total{};
    for(Reading r : readings) {
        total += r.temperature;
    }
    return total / readings.size();
}

double compute_median(const vector<Reading> &readings)
// compute the median of the temperatures in readings
// pre-condition: the size of readings must be at least one
{
    if(readings.size() == 0) error("compute_median: size of readings is zero");
    vector<double> tmps;
    for(Reading r : readings) {
        tmps.push_back(r.temperature);
    }
    sort(tmps);

    size_t n = tmps.size();
    if(n % 2)
        return tmps[n/2];

    return (tmps[n/2-1] + tmps[n/2]) / 2.0;
}

int main()
{
    try {
       
        vector<Reading> readings = read_from_file(kFile_name);

        Stats stats{};
        stats.mean = compute_mean(readings);
        stats.median = compute_median(readings);
        cout << stats << '\n';

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
