
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <fcntl.h>
#include <vector>
#include <unistd.h>
#include <utility>
#include <new>

#define SIZE 4096

std::vector<double>* get_from_jill()
{
    std::ifstream ifs{"jills_data.txt"};
    if(!ifs.is_open()) {
        throw std::ios_base::failure{"Failed to open file: jill_data.txt"};
    }

    auto *data = new(std::nothrow) std::vector<double>;

    double speed;
    while(ifs >> speed) {
        data->push_back(speed);
    }

    if(ifs.bad()) {
        throw std::ios_base::failure{"Error reading file: jill_data.txt"};
    }

    return data;
}

double* get_from_jack(int *count)
{

    std::ifstream ifs{"jacks_data.txt"};
    if(!ifs.is_open()) {
        throw std::ios_base::failure{"Failed to open file: jacks_data.txt"};
    }

    auto *data = new(std::nothrow) double[SIZE];

		double speed{};
		for(int i{}; ifs >> speed; ++i) {
				data[i] = speed;
				++*count;
		}

    if(ifs.bad()) {
        throw std::ios_base::failure{"Error reading file: jacks_data.txt"};
    }

    return data;
}

double* high(double *first, double *last)
{
    double h = -1;
    double *high{};
    for(double *p = first; p != last; ++p) {
        if(h < *p) {
            high = p;
            h = *p;
        }
    }

    return high;
}

double* ver1(double *first, double *second)
{
    double *high = first;
    double *p = first;
    while(p < second) {
        if(*p > *high) {
            high = p;
        }
        ++p;
    }

    return high;
}

double* ver2(double d[], int n)
{
    int first = 0;
    int last = n;
    double *high = &d[0];
    while(first < last) {
        if(d[first] > *high) {
            high = &d[first];
        }
        ++first;
    }
    return high;
}

void func()
{
    int jack_count = 0;
    double *jack_data = get_from_jack(&jack_count);
    std::vector<double> *jill_data = get_from_jill();

    double *jack_high = high(jack_data, jack_data + jack_count);
    std::vector<double> &v = *jill_data;
    double *jill_high = high(&v[0], &v[0] + v.size());

    
    std::cout << "Original version:\n";
    std::cout << "Jill's max: " << *jill_high
              << "; Jack's max: " << *jack_high << '\n';

    jack_high = ver1(jack_data, jack_data + jack_count);
    jill_high = ver1(&v[0], &v[0] + v.size());

    std::cout << "string version (without string):\n";
    std::cout << "Jill's max: " << *jill_high
              << "; Jack's max: " << *jack_high << '\n';

    jack_high = ver2(jack_data, jack_count);
    jill_high = ver2(v.data(), v.size());

    std::cout << "array version:\n";
    std::cout << "Jill's max: " << *jill_high
              << "; Jack's max: " << *jack_high << '\n';

    delete[] jack_data;
    delete jill_data;
}

int main()
{
    try {
       
        func();
        
        return 0;
    }
    catch(const std::ios_base::failure &e) {
        std::cerr << "Caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << '\n'
                  << "Error code: " << e.code() << '\n';
        return 2;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 3;
    }
} 