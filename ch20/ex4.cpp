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

template <typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for(Iterator p = first; p != last; ++p) {
        if(*high < *p) high = p;
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